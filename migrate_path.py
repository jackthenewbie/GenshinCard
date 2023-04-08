import os
import glob
import shutil
GENSHINCARD_PY_PATH = os.environ.get("GENSHINCARD_PY_PATH")
dest_assets = os.path.join(GENSHINCARD_PY_PATH, "Image/Assets")
os.makedirs(dest_assets, exist_ok=True)
#path of current python script
GENSHINCARD=os.path.dirname(os.path.realpath(__file__))
assets = os.path.join(GENSHINCARD, "Image/Assets")

# Get all files and folders from source directory
files = glob.glob(os.path.join(assets, "**"), recursive=True)

for file in files:
    # Skip directories
    if os.path.isdir(file):
        continue
    # Calculate destination path for each file
    dest_path = os.path.join(dest_assets, os.path.relpath(file, assets))
    # Create directories if necessary
    os.makedirs(os.path.dirname(dest_path), exist_ok=True)
    # Copy file to destination
    shutil.copy2(file, dest_path)