//
//  main.cpp
//  1306: 校门外的树
//
//  Created by czf on 15/11/16.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <set>
using namespace std;
set<int> subway;

int main(){
    int tree, n;
    while(scanf("%d%d",&tree,&n) == 2){;
        subway.clear();
        while(n--){
            int a, b;
            scanf("%d%d",&a,&b);
            for(int i = a; i <= b; i ++){
                if (i>=0 && i <=tree)
                    subway.insert(i);
            }
        }
        printf("%d\n",tree+1-subway.size());
    }
}
