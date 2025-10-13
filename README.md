// study note for LeetCode

# How to use　command
1. 解答用ディレクトリおよびファイルを作成する
```bash
fsolution [問題の名前] [解答に使う言語] [解答用テンプレで渡された関数名]
```
2. 解答ができたらコンパイル→実行まで一括で行う
```bash
lcbuild [問題の名前] [解答に使う言語] [解答用テンプレで渡された関数名]
```
- ホームディレクトリにいながらにして解答フォルダとコンパイル・テスト実行できるので活用してください。

# utility for debug
## util.h
- void print_str(const char *arr, int size) ... 文字列（char[]）を表示
- void print_nums(const int *arr, int size) ... 数列を表示
- void arrs_free(void **arrs, size_t arrssize) ... mallocした数列を逐次free
- void print_llist(struct ListNode* list)　... linklist.valを一括で表示
- void list_free(struct ListNode* list) ... listnodeを再帰的に逐次frees