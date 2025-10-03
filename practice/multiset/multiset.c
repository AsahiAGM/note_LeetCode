#include "../../util.c"
typedef struct s_node{
	int				key;
	struct s_node	*left;
	struct s_node	*right;
}	Node;

Node* insert(Node *list, int val)
{
	if (list){
		if (list->key >= val)
			list->left	= insert(list->left, val); //元nodeに再帰的に格納しなきゃいけないのを忘れがち
		else
			list->right = insert(list->right, val);
	}
	else
	{
		printf("insert:%d\n",val);
		list = malloc(sizeof(Node));
		list->key = val;
		list->left 	= NULL;
		list->right = NULL;
	}
	return (list);
}

void show(Node *list) // 表示は left,key,right の順にすれば昇順になる
{
	if (list)
	{
		show(list->left);
		printf("%d",list->key);
		show(list->right);
	}
}

Node* search(Node *list, int key)
{
	if (list){
		if (key == list->key)
			return (list);
		if (key < list->key)
			return (search(list->left, key));
		else
			return (search(list->right, key));
	}
	return (NULL);
}

Node* getmax(Node* list)
{
	if(list->right)
		return (getmax(list->right));
	return (list);
}

Node* getmin(Node* list)
{
	if(list->left)
		return (getmin(list->left));
	return (list);
}

Node* delete(Node* list, int target)
{
	if (list->key == target){
		Node* buf;
		if (list->left == NULL){
			buf = list->left;
			free(list);
			return (buf);
		}
		if (list->right == NULL){
			buf = list->right;
			free(list);
			return (buf);
		}
		Node* min = getmin(list->right); //　子二つの場合、右部分木の最小値をコピーし、右部分木からコピー元を消すという操作になる
		list->key = min->key;
		list->right = delete(list->right, min->key);
	}
	else{
		if (target < list->key)
			list->left	= delete(list->left, target);
		else
			list->right = delete(list->right, target);
	}
	return (list);
}

int main(void){
	// what's mean "set" -> it's gathered and sorted some without duplication
	int setA[] = {1,2,3}; //o. ok
	int setB[] = {2,3,3}; //x. not set 

	// what's mean "multiset" -> it's gathered and sorted some including duplication.
	int multisetA[] = {1,2,3}; //o. ok
	int multisetB[] = {2,3,3}; //o. ok

	// basic binary search tree
	int sample[5] = {3,1,5,2,4};
	Node *bst = NULL;

	for(int i=0; i<5; i++) //元nodeに再帰的に格納しなきゃいけないのを忘れがち(他の部分は概念も実装も合ってる)
		bst = insert(bst, sample[i]);
	show(bst);
	printf("\n");
	printf("search 3 -> %d\n",search(bst,3) != NULL);
	printf("search 10 -> %d\n",search(bst,10) != NULL);
	printf("max:%d\n",getmax(bst)->key);
	printf("min:%d\n",getmin(bst)->key);
}