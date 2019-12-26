/*
实现三维向量的内积和外积操作。三维向量使用结构体表示，如下：

struct Vector {
    int x;
    int y;
    int z;
};
内积函数：int VectorInnerProduct(struct Vector vec1, struct Vector vec2) 外积函数：struct Vector VectorCrossProduct(struct Vector vec1, struct Vector vec2)

Input
输入两行，每行三个数，表示一个三维向量

Output
输出两行，第一行输出内积（一个数），第二行输出外积（三个数）。

Sample Input
1 2 3
4 5 6
Sample Output
32
-3 6 -3
*/
struct Vector {
    int x;
    int y;
    int z;
};
struct Vector VectorCrossProduct(struct Vector vec1,struct Vector vec2){
    struct Vector ans;
    ans.x=vec1.y*vec2.z-vec1.z*vec2.y;
    ans.y=vec1.z*vec2.x-vec1.x*vec2.z;
    ans.z=vec1.x*vec2.y-vec1.y*vec2.x;
    return ans;
}

int VectorInnerProduct(struct Vector vec1,struct Vector vec2){
    return vec1.x*vec2.x+vec1.y*vec2.y+vec1.z*vec2.z;
}
#include <stdio.h>

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    struct Vector vec1 = {x, y, z};
    scanf("%d %d %d", &x, &y, &z);
    struct Vector vec2 = {x, y, z};
    printf("%d\n", VectorInnerProduct(vec1, vec2));
    struct Vector vec3 = VectorCrossProduct(vec1, vec2);
    printf("%d %d %d\n", vec3.x, vec3.y, vec3.z);
}