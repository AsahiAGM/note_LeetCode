#!/bin/bash
PROG_LANG=$1
PROBLEM=$2
SCRIPT=$3
OPTION=$4
TARGET="problems/$PROBLEM/$PROG_LANG"

case $PROG_LANG in
    cpp)
        g++ -std=c++23 -g -Wall -Werror -Wextra $OPTION "$TARGET/$SCRIPT" "$TARGET/main.cpp"
        ;;
    c)
        cc -g -Wall -Werror -Wextra $OPTION util.c "$TARGET/$SCRIPT" "$TARGET/main.c"
        ;;
    python)
        python3 $OPTION "$TARGET/$SCRIPT" "$TARGET/main.py"
        ;;
    cs)
        dotnet run --project $OPTION "$TARGET/$SCRIPT" "$TARGET/main.cs"
        ;;
    rust)
        rustc "$TARGET/$SCRIPT" "$TARGET/main.rs"
        ;;
    go)
        go run $OPTION "$TARGET/$SCRIPT" "$TARGET/main.go"
        ;;
    *)
        echo "Unknown language: $PROG_LANG"
        exit 1
        ;;
esac
