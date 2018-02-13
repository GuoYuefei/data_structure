# Graph
----
一个无向图的容器，用来解决有关图的问题。一个大学生练习数据结构的产物。
用于当作库使用
### 设计的类列表
|编号|名称|依赖类|备注|
|---|---|---|---|
|<center>1</center>|__Cost__|*NONE*|边中花费|
|<center>2</center>|__Edge__|*Cost*|记录边|
|<center>3</center>|__Node__|*Edge*|用id唯一标记node|
|<center>4</center>|__Graph__|*Node*|对外操作的最高层，最后一般对其操作|
----
+ ### usage
各类都有默认的方法实现，库功能的普遍性主要通过多态性实现

  - #### Cost
  >
  >>__重要数据__:  
   1. unsigned int 类型的花费  
  _因为可能用户存在类型花费上的需求，所以可以继承Cost类写出自己的类，并用来构造Edge类（下面会讲的一个依赖Cost的类）_
  >
  >>__重要操作__:  
   + 默认实现了get、set函数，optertor=、<

  - #### Edge
  >
  >> __重要数据__:
   1. Cost 类型的花费  
   2. unsigned int 类型的连接另一端顶点的ID  
  >
  >> __重要操作__:  
   + 两对get和set函数和optertor=、==

  - #### Node
  >
  >>__重要数据__:  
   1. unsigned int 类型的id 用于标记顶点
   2. vector<Edge> 类型的边集，记录该顶点有多少与之相关的边
   3. unsigned int 类型的iterEdge，是集合的_迭代器_,可能这里定义的迭代器和其他地方有所不同  
  >
  >>__重要操作__:  
   1. ```bool operator==(const Node& that) const```
   2. ```unsigned int getId() const```
   3. ```bool existEdge(unsigned int nextNodeId)```  
      ```bool existEdge(Edge e)```
   4. ```unsigned int edgePos(Edge e)```
   5. ```virtual vector<Edge> getadjEdges() const```
   6. ```virtual Edge getByNextId(uint nextNodeId)```
   7. ```bool setIterEdge(unsigned int iter)```
   8. ```unsigned int getIterEdge() const```
   9. ```void resetIter()```
   10. ```virtual bool addEdge(Edge e)```
   11. ```virtual bool addEdge(unsigned int id,Cost cost)```
   12. ```virtual bool removeEdge(const Edge& e)```
   13. ```virtual bool removeEdge(unsigned int id)```
   14. ```virtual void setEdgeCost(Edge e)```
   15. ```virtual void setEdgeCost(unsigned int a,Cost& cost)```
   16. ```virtual uint firstNeighbor()```
   17. ```virtual uint nextNeighbor()```

   ##### 关于函数功能
