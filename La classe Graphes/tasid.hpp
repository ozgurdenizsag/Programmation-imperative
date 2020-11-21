#ifndef TASID_HPP
#define TASID_HPP

#include <iostream>
#include <map>
#include <stdbool.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

template<class S, class P> class Tasid {
    private:
        map<int,pair <S,P> >m;
    public:
        Tasid();
    	~Tasid();
        pair<S,P> extraireMin(); //extraire m[1] puis réordonner 
        void ajouterElement(pair<S,P> ele); //V dans le tas ? oui : comparer le poids sinon l'ajouter
        void afficher();  // affichage  
};
#endif

template<class S,class P> Tasid<S,P>::Tasid(){}

template<class S,class P> Tasid<S,P>::~Tasid(){}

template<class S,class P> void Tasid<S,P>::ajouterElement(pair <S,P> ele){
    bool exist = false;
    int i = 0;
    for (typename map<int,pair<S,P> >::iterator it = (m).begin() ; it != (m).end() ; it++){
        if(((*it).second).first == ele.first){
            if (((*it).second).second > ele.second){
                ((*it).second).second = ele.second;
                for (int j = i; j < m.size(); j++){
                    if ((j != m.size()-1) && ( ele.second < m[j+1].second)){
                        m[j] = m[j+1];
                    } else {
                        m[j] = ele;
                        break;
                    }
                }
            }
            exist = true;
            break;
        }
        i++;
    }
    if (!exist){
        m[m.size()] = ele;
        for (int j = m.size()-1; j >= 0; j--){
            if ((j != 0) && ( ele.second > m[j-1].second)){
                m[j] = m[j-1];
            } else {
                m[j] = ele;
                break;
            }
        }
    }
}

template<class S,class P> void Tasid<S,P>::afficher(){
    if (m.size() > 0){
        for (typename map<int,pair<S,P> >::iterator it = (m).begin() ; it != (m).end() ; it++){
            cout << "[";
            cout << (*it).first;
            cout <<  ",(";
            pair<S,P> myPair = it->second;
            cout << myPair.first;
            cout << ",";
            cout << myPair.second;
            cout << ")]" << endl;
        }
    }
}

template<class S,class P> pair<S,P> Tasid<S,P>::extraireMin(){
    if(m.size()>0){
        pair<S,P> myPair = m[m.size()-1];
        m.erase(m.size()-1);
        return myPair;
    }else{
        throw length_error("Aucun élément à extraire");
    }
}