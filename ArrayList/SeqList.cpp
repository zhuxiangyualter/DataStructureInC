/**
*@author    渚相玉
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
//插入
    void insert(int index,T value){
        if (index < 0 || index > elements.size()) {
            throw std::runtime_error("索引越界");
        }
        elements.insert(elements.begin() + index, value);
    };
//根据索引寻值
    T getbyIndex(int index){
        if (index < 0 || index >= elements.size()) {
            throw std::runtime_error("索引越界");
        }
        return elements[index];
    };

//    T getbyValue(T x){
//        for (int i = 0; i < elements.size(); ++i) {
//            if(x == elements[i]){
//                return elements[i];
//            }
//        }
//        throw std::runtime_error("表中没有该元素");
//    };
//按值查索引
    int find(T value){
        for (int i = 0; i < elements.size(); ++i) {
            if(elements[i] == value){
                return i;
            }
        }
        return -1;
    };
//删除
    void remove(int index){
        if(index < 0 || index >= elements.size()){
            throw std::runtime_error("索引越界");
        }
        elements.erase(elements.begin() + index);
    };
//遍历
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
    cout<<"执行插入操作前数据为：";
    seqList.traverse();
    seqList.insert(3,5);
    cout<<"执行插入操作后数据为：";
    seqList.traverse();
    cout<<"执行删除操作前数据为：";
    seqList.traverse();
    seqList.remove(3);
    cout<<"执行删除操作后数据为：";
    seqList.traverse();
    cout<<"执行查找操作前数据为：";
    seqList.traverse();
    cout<<"查找元素5的索引为："<<seqList.find(5)<<endl;
    cout<<"执行查找操作后数据为：";
    seqList.traverse();
    cout<<"执行按索引查找操作前数据为：";
    seqList.traverse();
    cout<<"索引为3的元素为："<<seqList.getbyIndex(3)<<endl;
    cout<<"执行按索引查找操作后数据为：";
    seqList.traverse();
    return 0;
}
