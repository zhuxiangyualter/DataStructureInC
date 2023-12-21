/**
*@author    渚相玉
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-10-10.
*/

#include <iostream>

using namespace std;

template <typename T>
struct ListNode {
    T data;
    ListNode* next;

    ListNode(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkList {
private:
    ListNode<T>* head;
    int sizes;
public:
    // 无参构造函数
    LinkList() : head(nullptr), sizes(0) {}

    // 有参构造函数
    LinkList(const T* arr, int n) : head(nullptr), sizes(0) {
        if (n > 0) {
            head = new ListNode<T>(arr[0]);
            ListNode<T>* p = head;
            for (int i = 1; i < n; ++i) {
                p->next = new ListNode<T>(arr[i]);
                p = p->next;
            }
            sizes = n;
        }
    }

    // 析构函数
    ~LinkList() {
        ListNode<T>* p = head;
        while (p != nullptr) {
            ListNode<T>* q = p->next;
            delete p;
            p = q;
        }
        head = nullptr;
        sizes = 0;
    }
    // 求单链表的表长
    int size() const {
        return sizes;
    }

    // 按位查找
    ListNode<T>* get(int pos) const {
        if (pos < 0 || pos >= sizes) {
            return nullptr;
        }
        ListNode<T>* p = head;
        for (int i = 0; i < pos; ++i) {
            p = p->next;
        }
        return p;
    }

    // 按值查找
    int find(const T& val) const {
        ListNode<T>* p = head;
        int pos = 0;
        while (p != nullptr) {
            if (p->data == val) {
                return pos;
            }
            p = p->next;
            ++pos;
        }
        return -1;
    }
    //排序算法
    void sort() {
        ListNode<T>* p = head;
        ListNode<T>* q = nullptr;
        while (p != nullptr) {
            q = p->next;
            while (q != nullptr) {
                if (p->data > q->data) {
                    T temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
                q = q->next;
            }
            p = p->next;
        }
    }
    //判断是否有序
    bool isSorted() {
        ListNode<T>* p = head;
        while (p->next != nullptr) {
            if (p->data > p->next->data) {
                return false;
            }
            p = p->next;
        }
        return true;
    }
    // 插入元素
    bool insert(int pos, const T& val) {
        if (pos < 0 || pos > sizes) {
            return false;
        }
        if (pos == 0) {
            ListNode<T>* p = new ListNode<T>(val);
            p->next = head;
            head = p;
        } else {
            ListNode<T>* p = get(pos - 1);
            ListNode<T>* q = new ListNode<T>(val);
            q->next = p->next;
            p->next = q;
        }
        ++sizes;
        return true;
    }

    // 删除元素
    bool remove(int pos) {
        if (pos < 0 || pos >= sizes) {
            return false;
        }
        if (pos == 0) {
            ListNode<T>* p = head;
            head = head->next;
            delete p;
        } else {
            ListNode<T>* p = get(pos - 1);
            ListNode<T>* q = p->next;
            p->next = q->next;
            delete q;
        }
        --sizes;
        return true;
    }

    // 遍历整个单链表
    void traverse() const {
        ListNode<T>* p = head;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    // 原地逆置单链表

    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode<T>* prev = nullptr;
        ListNode<T>* current = head;
        ListNode<T>* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }
    //将两个有序表合并成一个有序表
    void merge(LinkList<T> &lst) {
        ListNode<T>* p = head;
        ListNode<T>* q = lst.head;
        ListNode<T>* r = nullptr;
        if (p->data < q->data) {
            r = p;
            p = p->next;
        } else {
            r = q;
            q = q->next;
        }
        ListNode<T>* s = r;
        while (p != nullptr && q != nullptr) {
            if (p->data < q->data) {
                s->next = p;
                p = p->next;
            } else {
                s->next = q;
                q = q->next;
            }
            s = s->next;
        }
        if (p != nullptr) {
            s->next = p;
        }
        if (q != nullptr) {
            s->next = q;
        }
        head = r;
    }
    //求两个集合的交集
    void intersection(LinkList<T> &lst) {
        ListNode<T>* p = head;
        ListNode<T>* q = lst.head;
        ListNode<T>* r = nullptr;
        if (p->data < q->data) {
            r = p;
            p = p->next;
        } else {
            r = q;
            q = q->next;
        }
        ListNode<T>* s = r;
        while (p != nullptr && q != nullptr) {
            if (p->data < q->data) {
                p = p->next;
            } else if (p->data > q->data) {
                q = q->next;
            } else {
                s->next = p;
                p = p->next;
                q = q->next;
                s = s->next;
            }
        }
        s->next = nullptr;
        head = r;
    }
    //判断两个集合是否相等
    bool equal(LinkList<T> &lst) {
        ListNode<T>* p = head;
        ListNode<T>* q = lst.head;
        while (p != nullptr && q != nullptr) {
            if (p->data != q->data) {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        if (p != nullptr || q != nullptr) {
            return false;
        }
        return true;
    }
    //删除单链表中的重复元素
    void deleteRepeat() {
        ListNode<T>* p = head;
        ListNode<T>* q = nullptr;
        while (p != nullptr) {
            q = p;
            while (q->next != nullptr) {
                if (p->data == q->next->data) {
                    ListNode<T>* r = q->next;
                    q->next = r->next;
                    delete r;
                } else {
                    q = q->next;
                }
            }
            p = p->next;
        }
    }
    //实现一元多项式相加
    void add(LinkList<T> &lst) {
        ListNode<T>* p = head;
        ListNode<T>* q = lst.head;
        ListNode<T>* r = nullptr;
        if (p->data < q->data) {
            r = p;
            p = p->next;
        } else {
            r = q;
            q = q->next;
        }
        ListNode<T>* s = r;
        while (p != nullptr && q != nullptr) {
            if (p->data < q->data) {
                s->next = p;
                p = p->next;
            } else if (p->data > q->data) {
                s->next = q;
                q = q->next;
            } else {
                p->data += q->data;
                s->next = p;
                p = p->next;
                q = q->next;
            }
            s = s->next;
        }
        if (p != nullptr) {
            s->next = p;
        }
        if (q != nullptr) {
            s->next = q;
        }
        head = r;
    }

};


int main() {
    // 创建空的单链表
    LinkList<int> lst1;

    // 创建带有初始值的单链表
    int arr[] = {1, 3, 5, 7, 9};
    LinkList<int> lst2(arr, 5);

    // 插入元素
    lst2.insert(2, 4);
    lst2.insert(4, 6);
    lst1.merge(lst2);
    
    // 输出单链表长度和所有元素
    cout << "List Length: " << lst2.size() << endl;
    lst2.traverse();

    // 删除元素
    lst2.remove(4);

    // 输出单链表长度和所有元素
    cout << "List Length: " << lst2.size() << endl;
    lst2.traverse();

    return 0;
}
