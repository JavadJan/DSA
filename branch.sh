#!/bin/bash

# Ensure we start from main
git checkout main || exit 1

for dir in */ ; do
    dir=${dir%/}   # remove trailing slash

    # Skip non-directories or special dirs
    [[ "$dir" == ".git" ]] && continue

    echo "=== Processing $dir ==="

    # Create branch
    git checkout -b "$dir"

    # Remove everything except this directory
    find . -mindepth 1 -maxdepth 1 ! -name "$dir" ! -name ".git" -exec rm -rf {} +

    # Optional: create README.md inside the directory
    if [[ ! -f "$dir/README.md" ]]; then
        echo "# $dir" > "$dir/README.md"
        echo "" >> "$dir/README.md"
        echo "Description of algorithms in $dir." >> "$dir/README.md"
    fi

    git add .
    git commit -m "Isolated directory '$dir' into its own branch"
    git push -u origin "$dir"

    # Return to main
    git checkout main
done
