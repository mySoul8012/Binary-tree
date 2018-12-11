# 目录说明
此目录存放相关树的类

# 类说明
## BitNode
节点类
### 方法
    BitNode();
    BitNode(T _data);

    // 数据域
    void setData(T _data);
    T getData();
    // 左节点
    void setLchild(BitNode*_lchild);
    BitNode<T>* getLchild();
    // 右节点
    void setRchild(BitNode* _rchild);
    BitNode<T> *getRchild();
    
## Tree
树类
### 方法

    Tree(); // 默认构造
    Tree(std::string& _str);    // 根据输入值创建
    // 输出二叉树
    void DispBiTNode();
    // 先序遍历二叉树
    void PreOrderTraverse();
    // 中序遍历二叉树
    void InOrderTraverse();
    // 后序遍历二叉树
    void PostOrderTraverse();
    // get和set方法
    int getDepth();
    void setDepth(int _depth);
    BitNode<char>* getBitNodeTop();
    void setBitNodeTop(BitNode<T>* _bitNodeTop);
    std::string getCreateString();
    void setCreateString(std::string _createString);
    
# 其他
时间，2018年12月11日 小
