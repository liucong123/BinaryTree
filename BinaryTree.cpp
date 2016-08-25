/*�������Ĵ����Լ�һЩ��������*/

#include<iostream>
#include<cstdlib>

using namespace std;

/*����ģ�崴���������ڵ�*/
template  <class T>
struct TreeNode
{
    T data;                      //�ڵ�ֵ
    TreeNode <T>*Lchild,*Rchild; //�ڵ����������
};

//�������Ľ���
template <class T> //ģ�淽��
void createBinaryTree(TreeNode<T> *&root )  //����ָ�������
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
        root=new TreeNode<T>();            //����һ���ڵ�
        root->data = nodeValue;
        createBinaryTree(root->Lchild);    //�ݹ鹹��������
        createBinaryTree(root->Rchild);    //�ݹ鹹��������
    }
}

//************************************************************************************
//���������������
template <class T>
void preOrder( TreeNode<T> * & p) //����ָ�������
{
    if(p)
    {
        cout<<p->data<<" ";
        preOrder(p->Lchild);
        preOrder(p->Rchild);
    }
}

//**************************************************************************************
//���������������
template <class T>
void inOrder(TreeNode<T> * & p) //����ָ�������
{

    if(p)
    {
        inOrder(p->Lchild);
        cout<<p->data<<" ";
        inOrder(p->Rchild);
    }
}

//**************************************************************************************
//�������ĺ������
template <class T>
void postOrder(TreeNode<T> *& p) //����ָ�������
{
    if(p)
    {
        postOrder(p->Lchild);
        postOrder(p->Rchild);
        cout<<p->data<<" ";
    }
}

//*************************************************************************************
//ͳ�ƶ������н��ĸ���
template<class T>
int countNode(TreeNode<T> * & p) //����ָ�������
{
    if(p == NULL) return 0;
    return 1+countNode(p->Lchild)+countNode(p->Rchild);
}

//***********************************************************************************
//������������
template<class T>
int depth(TreeNode<T> *& p) //����ָ�������
{
    if(p == NULL)
        return -1;
    int h1 = depth(p->Lchild);
    int h2 = depth(p->Rchild);
    if(h1>h2)return (h1+1);
    return h2+1;
}

//***********************************************************************************
//�����������ٲ���
//���׻����Ĵ���������void destroy(TreeNode<T>* p) ���������ᴴ��һ���ֲ�����ʱ���������洫�ݵ�ָ��
//��Ȼ2��ָ�붼ִ��ͬһ��ѿռ䣬delete�ֲ�ָ�� Ҳ��ɾ���������ṹ��ռ�õĶ��ڴ�
//����ȫ�ִ��ݵ��Ǹ�ָ�뽫��������ָ�룬���������Ԥ�ϵĴ���
//void destroy(TreeNode<T> *& p) �˺����Ĳ���Ϊȫ��ָ���һ������������ȫ��ָ��rootNode����
//  ����p = NULL;�ܴﵽ�ÿ�ָ�������
//��ѡ�ķ������ڵ�����destroy����֮������������ִ��rootNode = NULL����
template<class T>
void destroy(TreeNode<T> *& p)  //����ָ�������,���ٺ������������ٶ������еĸ������
{
    if(p)
    {
        //���� return֮�� û��ִ��delete p
        //return destroy(p->Lchild);
        //return destroy(p->Rchild);

        destroy(p->Lchild);
        destroy(p->Rchild);

        //deleteֻ���ͷ����û�ͨ��new��ʽ�ڶ���������ڴ棬
        //��ͨ�����������ķ�ʽ��ϵͳ��������ջ�ڴ治��ʹ��deleteɾ��

        //delete��free����һ�������޸���������Ӧָ��ָ������ݣ�Ҳ���޸�ָ�뱾��
        //ֻ���ڶ��ڴ����ṹ�н�ָ��ָ������ݱ��Ϊ�ɱ����·���
        delete p;

        //�����ڴ��ͷ� ջ��ָ�벢������
        //��ʱpָ��ĵ�ַδ֪,��ʱִ��*p = ? �����ᵼ�²���Ԥ�ϵĴ���
        //���ǿ������¸�ֵp = &x;
        //���delete֮���P�ÿ�
        p = NULL;

    }
}

//********************************************************************************
//�����������
int main ()
{
    TreeNode<int> * rootNode = NULL;
    int choiced = 0;
    while(true)
    {
        system("cls"); //����
        cout<<"\n\n\n                              ---������---\n\n\n";
        cout<<"                     1������������                2���������������\n";
        cout<<"                     3���������������            4���������������\n";
        cout<<"                     5��ͳ�ƽ������              6���鿴�����    \n";
        cout<<"                     7�����ٶ�����                0���˳�\n\n";
        cout<<"             ��ѡ�������";
        cin>>choiced;
        if(choiced == 0)
            return 0;
        else if(choiced == 1)
        {
            system("cls");
            cout<<"������ÿ����㣬�س�ȷ�ϣ�����-1������\n";
            createBinaryTree(rootNode );
        }
        else if(choiced == 2)
        {
            system("cls");
            cout<<"������������������\n";
            preOrder(rootNode);
            cout<<endl;
            system("pause"); //��ͣ��Ļ
        }
        else if(choiced == 3)
        {
            system("cls");
            cout<<"������������������\n";
            inOrder(rootNode);
            cout<<endl;
            system("pause");
        }
        else if(choiced == 4)
        {
            system("cls");
            cout<<"������������������\n";
            postOrder(rootNode);
            cout<<endl;
            system("pause");
        }
        else if(choiced == 5)
        {
            system("cls");
            int count = countNode(rootNode);
            cout<<"�������н������Ϊ"<<count<<endl;
            system("pause");
        }
        else if(choiced == 6)
        {
            system("cls");
            int dep = depth(rootNode);
            cout<<"�˶����������Ϊ"<<dep<<endl;
            system("pause");
        }
        else if(choiced == 7)
        {
            system("cls");
            cout<<"�������ѱ����٣�\n";
            destroy(rootNode);
            cout<<endl;
            system("pause");
        }
        else
        {
            system("cls");
            cout<<"\n\n\n\n\n\t����ѡ��\n";
        }

    }
}
