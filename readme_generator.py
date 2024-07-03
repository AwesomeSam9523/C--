# This is for generating the README file

import typing as t
import os
import datetime
import pathlib

now = datetime.datetime.now()
last_updated = now.strftime("%d %b'%y")

base = f"""# 🍵 Some basic C++ programs

### These are some programs I make while I learn C++.
`Last Updated: {last_updated}`

"""
extra = ""
markup = "### List of all programs:\n"
done_levels = []

def get_filename(folder: str) -> str:
    return " ".join([x.capitalize() for x in folder.split("_")[1:]])

def get_sorted_files(folder: t.Optional[str]):
    """This sorts the inner files in ascending order"""
    files = os.listdir(folder)
    files = [x for x in files if x not in [".git", "README.md", "readme_generator.py", ".gitignore", "CMakeLists.txt", ".vscode", ".idea", "cmake-build-debug"]]
    files = [x for x in files if not x.endswith(".exe")]
    if folder is not None and all(x.split("_")[0].isdigit() for x in files):
        files = sorted(files, key=lambda x: int(x.split("_")[0]))
    elif folder is None:
        files = sorted(files, key=lambda x: int(x.split("_")[0]))

    return files

def get_name_and_path(folder: t.Optional[str] = None, level: int = 0) -> None:
    global markup
    
    for file in get_sorted_files(folder):
        if folder is None:
            filepath = file
        else:
            filepath = os.path.join(folder, file)

        if folder and "\\" in folder:
            folder = folder.split("\\")[-1]

        filename = get_filename(folder or file)
        # print(folder, filename, file)
        if file.endswith(".cpp"):
            filepath = filepath.replace("\\", "/")
            markup += f"{level * '  '}- [{filename}]({filepath})\n"
    
        if os.path.isdir(filepath):
            # print(folder)
            if folder not in done_levels and level != 0:
                markup += f"{level * '  '}- {filename}\n"
                done_levels.append(folder)
            get_name_and_path(filepath, level + 1)
            continue

def get_extra_info():
    path = pathlib.Path('./')
    lines = 0
    files = 0
    char = 0
    for item in path.rglob('*.cpp'):
        files += 1

        with item.open() as of:
            for line in of.readlines():
                line = line.strip()
                lines += 1
                char += len(line)

    return f"- Total files: `{files:,}`\n- Total lines: `{lines:,}`\n- Total characters: `{char:,}`\n\n"

if __name__ == "__main__":
    get_name_and_path()
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(base + get_extra_info() + markup)
