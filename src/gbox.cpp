#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <cstring>
const std::string projectFolderPath = "./python/New-Project";
const std::string mainFilePath = projectFolderPath + "/main.py";
const std::string gboxLibsFilePath = projectFolderPath + "/gbox_libs.py";

void createProject() {
    std::filesystem::path folderPath = projectFolderPath;
    try {
        if (std::filesystem::create_directory(folderPath)) {
            std::cout << "フォルダが作成されました。\n";
        } else {
            std::cout << "フォルダの作成に失敗しました。\n";
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "エラー: " << e.what() << '\n';
    }

    auto writeFile = [](const std::string& filePath, const std::string& content) {
        std::ofstream file(filePath);
        if (file.is_open()) {
            file << content;
            file.close();
            std::cout << "ファイルに書き込みました。\n";
        } else {
            std::cerr << "ファイルが開けませんでした。\n";
        }
    };

    writeFile(mainFilePath, "import gbox_libs as gbox_libs\n\nclass Example():\n   def __init__(self) -> None:\n       super().__init__()\n       # スクリプトをここに書いてください\n\nExample()");
    writeFile(gboxLibsFilePath, "import tkinter as tk\nimport requests\n\n#gbox_libs 1.0\n\nclass gb_tk():\n    // ... (your existing content)");
}

void runProject(const std::string& appName) {
    std::string command = "./bin/python3 ./python/" + appName + "/main.py";
    std::system(command.c_str());
}

int main(int argc, char** argv) {
    if (argc > 1 && strcmp(argv[1], "-m") == 0) {
        createProject();
    } else {
        std::string appName;
        std::cout << "フォルダ名を入力:";
        std::cin >> appName;
        runProject(appName);
    }

    return 0;
}
