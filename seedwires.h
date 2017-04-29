#ifndef SEEDWIRES_H
#define SEEDWIRES_H
#include <iostream>
#include <vector>
#include <math.h>
template <class T>
T countS (const std::vector<std::vector<T>> &distance,const std::vector<std::vector<T>> &wires,std::vector<T> place) {
   // std::cout<<"countSS placeSize"<<place.size()<<std::endl;
    //for (unsigned i=0;i<place.size();i++)
      //  std::cout<<"i="<<i<<" comp "<<place[i]<<std::endl;;
    T bS=0;
    for (unsigned int count1=0;count1<place.size();count1++) {
        for (unsigned int count2=1;count2+count1<place.size();count2++) {
           // std::cout<<"count1 "<<count1<<" count1+count2 "<<count1+count2<<std::endl;
            bS=bS+distance[count1] [count1+count2]*wires[place[count1]][place[count1+count2]];
        }
    }
    return bS;



}
template <class T>
void  spaceComponentsT( T variant,T free,T choose,const std::vector<std::vector<T>> &distance,const std::vector<std::vector<T>> &wires,std::vector<T> options,std::vector<T> place,T &bestS)
{
    //std::cout<<"CHOOSE"<<choose<<std::endl;
    std::swap(options[0+free-1],options[choose]);
   // std::cout<<"SWAP"<<std::endl;
    place.push_back(variant);

    T S=countS(distance,wires,place);
    //std::cout<<"S="<<S<<std::endl;
    if ((S>bestS) && (bestS!=0)) {
        std::cout<<"S="<<S<<" Best S="<<bestS<<std::endl;
        return ;
    }
    if (place.size()==options.size()) {
        bestS=S;
        std::cout<<"Best solution now="<<bestS<<std::endl;
        for (unsigned int p=0;p<place.size();p++)
            std::cout<<place[p]<<" ";
        std::cout<<std::endl;
        return;
    }

    for (unsigned int var=0;var+free<options.size();var++)
    {
       // std::cout<<"SS "<<var+free<<" DD "<<options[var+free]<<std::endl;
        spaceComponentsT(options[var+free],(free+1),(int)(var+free),distance,wires,options,place,bestS);
    }
    return ;



}

template <class T>
void  spaceComponents(const std::vector<std::vector<T>> &distance,const std::vector<std::vector<T>> &wires,std::vector<T> options,std::vector<T> place,T &bestS)
{
    std::cout<<"START"<<std::endl;
     for (unsigned int var=0;var<options.size();var++)
     { //std::cout<<"!"<<var<<std::endl;
         spaceComponentsT(options[var],1,(int)var,distance,wires,options,place,bestS);
     }
  std::cout<<"MINIMUM S="<<bestS<<std::endl;
  return;

}


#endif // SEEDWIRES_H
