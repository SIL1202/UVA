for file in $(git ls-files --deleted); do
  new_file=$(find . -type f -name "$(basename "$file")" | head -n 1)
  if [ -n "$new_file" ]; then
    echo "Restoring $file -> $new_file"
    git mv "$new_file" "$file"
  fi
done
