/**
*@author    �����
*@version   v0.9.16
*@Session For U
*Created by 15708 on 2023-10-10.
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class SeqList {
private:
    vector<T> elements;
    int capacity;

public:
    SeqList(vector<T> cur) : elements(cur) {}
    SeqList() {}
//
    int length(){
        return elements.size();
    };
//����
    void insert(int index,T value){
        if (index < 0 || index > elements.size()) {
            throw std::runtime_error("����Խ��");
        }
        elements.insert(elements.begin() + index, value);
    };
//��������Ѱֵ
    T getbyIndex(int index){
        if (index < 0 || index >= elements.size()) {
            throw std::runtime_error("����Խ��");
        }
        return elements[index];
    };

//    T getbyValue(T x){
//        for (int i = 0; i < elements.size(); ++i) {
//            if(x == elements[i]){
//                return elements[i];
//            }
//        }
//        throw std::runtime_error("����û�и�Ԫ��");
//    };
//��ֵ������
    int find(T value){
        for (int i = 0; i < elements.size(); ++i) {
            if(elements[i] == value){
                return i;
            }
        }
        return -1;
    };
//ɾ��
    void remove(int index){
        if(index < 0 || index >= elements.size()){
            throw std::runtime_error("����Խ��");
        }
        elements.erase(elements.begin() + index);
    };
//����
    void traverse(){
        for (int i = 0; i < elements.size(); ++i) {
            cout<<elements[i]<<"  ";
        }
        cout<<endl;
    };
};
int main() {
    vector<int> v = {4,2,6,8,10,12,14,16,19,18};
    SeqList<int> seqList(v);
    cout<<"ִ�в������ǰ����Ϊ��";
    seqList.traverse();
    seqList.insert(3,5);
    cout<<"ִ�в������������Ϊ��";
    seqList.traverse();
    cout<<"ִ��ɾ������ǰ����Ϊ��";
    seqList.traverse();
    seqList.remove(3);
    cout<<"ִ��ɾ������������Ϊ��";
    seqList.traverse();
    cout<<"ִ�в��Ҳ���ǰ����Ϊ��";
    seqList.traverse();
    cout<<"����Ԫ��5������Ϊ��"<<seqList.find(5)<<endl;
    cout<<"ִ�в��Ҳ���������Ϊ��";
    seqList.traverse();
    cout<<"ִ�а��������Ҳ���ǰ����Ϊ��";
    seqList.traverse();
    cout<<"����Ϊ3��Ԫ��Ϊ��"<<seqList.getbyIndex(3)<<endl;
    cout<<"ִ�а��������Ҳ���������Ϊ��";
    seqList.traverse();
    return 0;
}

