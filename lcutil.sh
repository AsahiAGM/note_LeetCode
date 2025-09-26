#!/bin/bash
setlang () 
{ 
    echo "  setlang..."
    lang="$1"
    probname="$2"
    cd "$lang" && touch "main.$lang" "$probname.$lang"
}
solution () 
{ 
    echo "  solution..."
    cd problems
    mkdir "$1" && cd "$1" && mkdir c cpp cs py rust go
}
fsolution()
{
    if [[ $1 == "-h" || $1 == "--help" ]]; then
        cat .man_util/fsolution.txt
        return 0
    fi

    if [[ $# -ne 3 ]]; then
        echo "syntax ERROR. please read this command help --> fsolution -h or --help"
        return 1
    fi

    echo "fsolution..."
    solution "$1"
    setlang "$2" "$3"
    cd ../../..
}