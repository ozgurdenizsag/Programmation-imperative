#ifndef TAS_HPP
#define TAS_HPP

#include <iostream>
#include <map>
#include <stdbool.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

template<class T> class Tas {
    private:
        vector< T > v;
    public:
    	Tas();
        Tas(vector<T> vec);
    	~Tas();
    	T extraireMin();
    	void ajouterElement(T ele);
        void reordonner();
    	bool rechercherElement(T ele);
    	void afficher();     
};
#endif

template<class T> Tas<T>::Tas(){}

template<class T> Tas<T>::~Tas(){}

template<class T> Tas<T>::Tas(vector<T> vec){
    v = vec;    
}

template<class T> void Tas<T>::reordonner(){
    if(v.size()>1){
        for (int i = v.size()-1; i >=0; i--){
            int indPere = (i-1)/2;
            if (v[indPere] > v[i]){
                T e = v[i];
                v[i] = v[indPere];
                v[indPere] = e;
            }
        }  
    } 
}

template<class T> void Tas<T>::ajouterElement(T ele){
    v.push_back(ele);
    reordonner();
}

template<class T> void Tas<T>::afficher(){
    cout<<"[";
    for (typename vector<T>::const_iterator it = (v).begin() ; it != (v).end() ; it++){
        cout<<*it;
        if(it!=v.end()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

template<class T> T Tas<T>::extraireMin(){
    if(v.size()>0){
        T min = v.front();
        v.erase(v.begin());
        reordonner();
        return min;
    }else{
        throw length_error("Aucun élément à extraire");
    }
}

template<class T> bool Tas<T>::rechercherElement(T ele){
    if(v.size()>0){
        for (typename vector<T>::const_iterator it = (v).begin() ; it != (v).end() ; it++){
            if(*it==ele){
                return true;
            }
        }
    }
    return false;
}