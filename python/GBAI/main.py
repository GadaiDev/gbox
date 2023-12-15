import tkinter as tk
import zipfile
import glob
import os
import re

if not os.path.exists("tmp"):
    os.makedirs("tmp")

# zipファイルを開く
class Example():
   def __init__(self) -> None:
        for app in glob.glob("./tmp/*.zip"):
            extracted_dir = re.sub(r"\./tmp/(.*)\.zip",r"./python/\1/",app)
            zip_file_path = f'{app}'
            print(extracted_dir)
            with zipfile.ZipFile(app, 'r') as zip_ref:
            # 解凍先ディレクトリが存在しない場合は作成する
                if not os.path.exists(extracted_dir):
                    os.makedirs(extracted_dir)

                zip_ref.extractall(extracted_dir)
            os.remove(f"{app}")
Example()