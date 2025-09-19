#pragma once
#include "iconutil.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "config.h"
#include <shlobj.h>
#include <filesystem>

std::string IconUtil::selectPath() {
    BROWSEINFOW bi = { 0 };
    bi.lpszTitle = L"Select the desktop folder:";
    LPITEMIDLIST pidl = SHBrowseForFolderW(&bi);

    if (pidl != nullptr) {
        wchar_t path[MAX_PATH];
        if (SHGetPathFromIDListW(pidl, path)) {
            CoTaskMemFree(pidl);
            // Convert wchar_t* to std::string
            int len = WideCharToMultiByte(CP_UTF8, 0, path, -1, nullptr, 0, nullptr, nullptr);
            std::string result(len, 0);
            WideCharToMultiByte(CP_UTF8, 0, path, -1, &result[0], len, nullptr, nullptr);
            // Remove trailing null character
            if (!result.empty() && result.back() == '\0') result.pop_back();
            return result;
        }
        CoTaskMemFree(pidl);
    }
    return "";
}