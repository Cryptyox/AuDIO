#pragma once

enum class GroupingMode {
    Folders = 1,
    Squared = 2,
    NoGrouping = 3
};

enum class SortingMode {
    Alphabetical = 1,
    DateAdded = 2,
    Smart = 3
};

struct Config {
    GroupingMode grouping = GroupingMode::Folders;
    SortingMode sorting = SortingMode::Alphabetical;
    bool autoErrorCorrection = false;
};