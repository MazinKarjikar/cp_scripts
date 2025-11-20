#!/bin/bash

# RUN FROM THIS DIRECTORY

# Configuration
TEMPLATE_CPP="template.cpp"
TEMPLATE_PYTHON="template.py"
PREFIX_CPP="cpp-template"
PREFIX_PYTHON="python-template"

# Paths
VSCODE_SNIPPETS_DIR="../../.vscode"
SNIPPETS_FILE="${VSCODE_SNIPPETS_DIR}/snippets.code-snippets"

# Error handling function
error_exit() {
    echo "Error: $1" >&2
    exit 1
}

# Ensure the parent directory is "templates"
[ "$(basename "$PWD")" != "templates" ] \
    && error_exit "Current working directory must be 'templates'"

# Check if snippets directory exists
[ ! -d "$VSCODE_SNIPPETS_DIR" ] && error_exit "VSCode snippets directory not found"

# Create the snippets file if it doesn't exist
[ ! -f "$SNIPPETS_FILE" ] && echo "{}" > "$SNIPPETS_FILE"

# Escape special characters for JSON
escape_json() {
    local input="$1"
    # Escape backslashes, quotes, and other special characters
    # Preserve all original spacing
    echo "$input" | sed -e 's/\\/\\\\/g' -e 's/"/\\"/g' -e 's/\$/\\$/g'
}

# Generate snippet JSON for a given template
generate_snippet() {
    local file="$1"
    local name="$2"
    local prefix="$3"
    local description="$4"

    # Start of the snippet JSON
    printf '  "%s": {\n' "$name"
    printf '    "prefix": "%s",\n' "$prefix"
    printf '    "description": "%s",\n' "$description"
    printf '    "body": [\n'

    # Process file lines with escaping
    local line_count=0
    # Use || [ -n "$line" ] to ensure last line is processed even without newline
    while IFS= read -r line || [ -n "$line" ]; do
        # Escape the line while preserving original spacing
        escaped_line=$(escape_json "$line")

        # Add comma if not the first line
        if [ $line_count -gt 0 ]; then
            printf ',\n'
        fi

        # Print escaped line
        printf '      "%s"' "$escaped_line"

        ((line_count++))
    done < "$file"

    # Close body and snippet
    printf '\n    ]\n'
    printf '  }'
}

# Update snippets for each language
update_snippets() {
    # Temporary file for new content
    temp_file=$(mktemp)

    # Start with an opening brace
    printf '{\n' > "$temp_file"

    local first_snippet=true

    # Process C++ template
    if [ -f "$TEMPLATE_CPP" ]; then
        if [ "$first_snippet" = false ]; then
            printf ',\n' >> "$temp_file"
        fi
        generate_snippet "$TEMPLATE_CPP" "CPP-TEMPLATE" "$PREFIX_CPP" "C++ template code" >> "$temp_file"
        first_snippet=false
    fi

    # Process Python template
    if [ -f "$TEMPLATE_PYTHON" ]; then
        if [ "$first_snippet" = false ]; then
            printf ',\n' >> "$temp_file"
        fi
        generate_snippet "$TEMPLATE_PYTHON" "PYTHON-TEMPLATE" "$PREFIX_PYTHON" "Python template code" >> "$temp_file"
        first_snippet=false
    fi

    # Close the JSON object
    printf '\n}\n' >> "$temp_file"

    # Move the new file to the snippets file
    mv "$temp_file" "$SNIPPETS_FILE"

    echo "Snippets updated in '$SNIPPETS_FILE'"
}

# Run the update
update_snippets