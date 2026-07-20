import os
import sys

workspace = sys.argv[1]
cpp_file = sys.argv[2]

filename = os.path.splitext(os.path.basename(cpp_file))[0]

notes_dir = os.path.join(workspace, "Notes")
os.makedirs(notes_dir, exist_ok=True)

note_path = os.path.join(notes_dir, filename + ".md")

if not os.path.exists(note_path):
    with open(note_path, "w", encoding="utf-8") as f:
        f.write(f"""## Problem



---
## Solution



---
## Code

```codefile
../{filename}.cpp
```
""")