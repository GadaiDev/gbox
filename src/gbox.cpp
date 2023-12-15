#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <cstring>
#include <cstdlib> // For std::system

const std::string projectFolderPath = "./python/New-Project";
const std::string mainFilePath = projectFolderPath + "/main.py";
const std::string gboxLibsFilePath = projectFolderPath + "/gbox_libs.py";
const std::string requireFilePath = projectFolderPath + "/require.txt";

void createProject() {
    std::filesystem::path folderPath = projectFolderPath;
    try {
        if (std::filesystem::create_directory(folderPath)) {
            std::cout << "フォルダが作成されました。\n";

            // Create a sample require.txt file with dependencies
            std::ofstream requireFile(requireFilePath);
            if (requireFile.is_open()) {
                requireFile << "requests==2.26.0\n";
                requireFile.close();
                std::cout << "require.txt ファイルが作成されました。\n";
            } else {
                std::cerr << "require.txt ファイルが作成できませんでした。\n";
            }

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
}

void runProject(const std::string& appName) {
    std::string command = "./bin/python3 ./python/" + appName + "/main.py";
    std::system(command.c_str());
}

int main(int argc, char** argv) {
    if (argc > 1 && strcmp(argv[1], "-m") == 0) {
        createProject();
    } else {
        std::string appName(argv[1]);
        if (argc > 2 && strcmp(argv[2], "--install") == 0) {
            std::string pipInstallCommand = "./bin/python3 -m pip install -r ./python/" + appName + "/require.txt";
            int pipResult = std::system(pipInstallCommand.c_str());
            if (pipResult == 0) {
                std::cout << "依存関係がインストールされました。\n";
            } else {
                std::cerr << "依存関係のインストールに失敗しました。\n";
            }
        }
        runProject(appName);
    }

    return 0;
}
