import os
import subprocess


def run_clang_format(root_dir):
    # Walk through the directory recursively
    for root, _, files in os.walk(root_dir):
        for file in files:
            if file.endswith('.cpp'):
                file_path = os.path.join(root, file)
                # Run clang-format on the file
                subprocess.run(['clang-format', '-i', file_path], check=True)
                print(f"Formatted: {file_path}")


if __name__ == "__main__":
    # Set the root directory to current directory
    root_dir = os.getcwd()
    run_clang_format(root_dir)
