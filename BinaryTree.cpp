/*二叉树的创建以及一些基本操作*/

#include<iostream>
#include<cstdlib>

using namespace std;

/*利用模板创建二叉树节点*/
template  <class T>
struct TreeNode
{
    T data;                      //节点值
    TreeNode <T>*Lchild,*Rchild; //节点的左右子数
};

//二叉树的建立
template <class T> //模版方法
void createBinaryTree(TreeNode<T> *&root )  //传递指针的引用
{
    TreeNode<T>* p = root;
    T nodeValue ;
    cin>>nodeValue;
    if(nodeValue==-1)
    {
        root=NULL;
    }
    else
    {
        root=new TreeNode<T>();            //构造一个节点
        root->data = nodeValue;
        createBinaryTree(root->Lchild);    //递归构造左子树
        createBinaryTree(root->Rchild);    //递归构造右子树
    }
}

//************************************************************************************
//二叉树的先序遍历
template <class T>
void preOrder( TreeNode<T> * & p) //传递指针的引用
{
    if(p)
    {
        cout<<p->data<<" ";
        preOrder(p->Lchild);
        preOrder(p->Rchild);
    }
}

//**************************************************************************************
//二叉树的中序遍历
template <class T>
void inOrder(TreeNode<T> * & p) //传递指针的引用
{

    if(p)
    {
        inOrder(p->Lchild);
        cout<<p->data<<" ";
        inOrder(p->Rchild);
    }
}

//**************************************************************************************
//二叉树的后序遍历
template <class T>
void postOrder(TreeNode<T> *& p) //传递指针的引用
{
    if(p)
    {
        postOrder(p->Lchild);
        postOrder(p->Rchild);
        cout<<p->data<<" ";
    }
}

//*************************************************************************************
//统计二叉树中结点的个数
template<class T>
int countNode(TreeNode<T> * & p) //传递指针的引用
{
    if(p == NULL) return 0;
    return 1+countNode(p->Lchild)+countNode(p->Rchild);
}

//***********************************************************************************
//求二叉树的深度
template<class T>
int depth(TreeNode<T> *& p) //传递指针的引用
{
    if(p == NULL)
        return -1;
    int h1 = depth(p->Lchild);
    int h2 = depth(p->Rchild);
    if(h1>h2)return (h1+1);
    return h2+1;
}

//***********************************************************************************
//二叉树的消毁操作
//容易混淆的错误声明：void destroy(TreeNode<T>* p) 这种声明会创建一个局部的临时对象来保存传递的指针
//虽然2个指针都执行同一块堆空间，delete局部指针 也会删除二叉树结构所占用的堆内存
//但是全局传递的那个指针将会是垃圾指针，会产生不可预料的错误
//void destroy(TreeNode<T> *& p) 此函数的参数为全局指针的一个别名，代表全局指针rootNode本身
//  这样p = NULL;能达到置空指针的左右
//可选的方案是在调用完destroy方法之后，在主函数中执行rootNode = NULL操作
template<class T>
void destroy(TreeNode<T> *& p)  //传递指针的引用,消毁函数，用来消毁二叉树中的各个结点
{
    if(p)
    {
        //错误 return之后 没有执行delete p
        //return destroy(p->Lchild);
        //return destroy(p->Rchild);

        destroy(p->Lchild);
        destroy(p->Rchild);

        //delete只能释放由用户通过new方式在堆中申请的内存，
        //是通过变量声明的方式由系统所声明的栈内存不能使用delete删除

        //delete和free函数一样，不修改它参数对应指针指向的内容，也不修改指针本身，
        //只是在堆内存管理结构中将指针指向的内容标记为可被重新分配
        delete p;

        //堆上内存释放 栈上指针并不销毁
        //此时p指向的地址未知,此时执行*p = ? 操作会导致不可预料的错误
        //但是可以重新赋值p = &x;
        //最好delete之后把P置空
        p = NULL;

    }
}

//********************************************************************************
//主函数的设计
int main ()
{
    TreeNode<int> * rootNode = NULL;
    int choiced = 0;
    while(true)
    {
        system("cls"); //清屏
        cout<<"\n\n\n                              ---主界面---\n\n\n";
        cout<<"                     1、创建二叉树                2、先序遍历二叉树\n";
        cout<<"                     3、中序遍历二叉树            4、后序遍历二叉树\n";
        cout<<"                     5、统计结点总数              6、查看树深度    \n";
        cout<<"                     7、消毁二叉树                0、退出\n\n";
        cout<<"             请选择操作：";
        cin>>choiced;
        if(choiced == 0)
            return 0;
        else if(choiced == 1)
        {
            system("cls");
            cout<<"请输入每个结点，回车确认，并以-1结束：\n";
            createBinaryTree(rootNode );
        }
        else if(choiced == 2)
        {
            system("cls");
            cout<<"先序遍历二叉树结果：\n";
            preOrder(rootNode);
            cout<<endl;
            system("pause"); //暂停屏幕
        }
        else if(choiced == 3)
        {
            system("cls");
            cout<<"中序遍历二叉树结果：\n";
            inOrder(rootNode);
            cout<<endl;
            system("pause");
        }
        else if(choiced == 4)
        {
            system("cls");
            cout<<"后序遍历二叉树结果：\n";
            postOrder(rootNode);
            cout<<endl;
            system("pause");
        }
        else if(choiced == 5)
        {
            system("cls");
            int count = countNode(rootNode);
            cout<<"二叉树中结点总数为"<<count<<endl;
            system("pause");
        }
        else if(choiced == 6)
        {
            system("cls");
            int dep = depth(rootNode);
            cout<<"此二叉树的深度为"<<dep<<endl;
            system("pause");
        }
        else if(choiced == 7)
        {
            system("cls");
            cout<<"二叉树已被消毁！\n";
            destroy(rootNode);
            cout<<endl;
            system("pause");
        }
        else
        {
            system("cls");
            cout<<"\n\n\n\n\n\t错误选择！\n";
        }

    }
}
