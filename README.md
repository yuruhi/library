# library

競技プログラミングで使うライブラリ集です

## [DP](https://github.com/yuruhi/library/tree/master/DP)

- [01ナップサック](https://github.com/yuruhi/library/blob/master/DP/Knapsack.cpp)
- [最長共通部分列(LCS)](https://github.com/yuruhi/library/blob/master/DP/LCS.cpp)
- [最長増加部分列(LIS)](https://github.com/yuruhi/library/blob/master/DP/LIS.cpp)
- [編集距離](https://github.com/yuruhi/library/blob/master/DP/Levenshtein.cpp)
- [ヒストグラム中の最大長方形](https://github.com/yuruhi/library/blob/master/DP/MaximumRectangle.cpp)

## [DataStructure](https://github.com/yuruhi/library/tree/master/DataStructure)

- [UnionFind](https://github.com/yuruhi/library/blob/master/DataStructure/UnionFind.cpp)
- [重み付きUnionFind](https://github.com/yuruhi/library/blob/master/DataStructure/WeightedUnionFind.cpp)
- [Binary Indexed Tree](https://github.com/yuruhi/library/blob/master/DataStructure/BinaryIndexedTree.cpp)
- [一点更新・区間クエリ](https://github.com/yuruhi/library/blob/master/DataStructure/SegmentTree.cpp)
- [区間加算・一点更新](https://github.com/yuruhi/library/blob/master/DataStructure/RangeAddQuery.cpp)
- [区間加算・区間最大](https://github.com/yuruhi/library/blob/master/DataStructure/RAQRMaxQ.cpp)
- [区間加算・区間最小](https://github.com/yuruhi/library/blob/master/DataStructure/RAQRminQ.cpp)
- [区間加算・区間和](https://github.com/yuruhi/library/blob/master/DataStructure/RAQRSQ.cpp)
- [区間更新・区間最小](https://github.com/yuruhi/library/blob/master/DataStructure/RUQRminQ.cpp)
- [区間加算更新・区間和](https://github.com/yuruhi/library/blob/master/DataStructure/RAUQRSQ.cpp)

## [Geometry](https://github.com/yuruhi/library/tree/master/Geometry)

- [テンプレート](https://github.com/yuruhi/library/blob/master/Geometry/Geometric.cpp)

## [Graph](https://github.com/yuruhi/library/tree/master/Math)

- [テンプレート](https://github.com/yuruhi/library/blob/master/Graph/GraphTemplate.cpp)

### 最短経路

- [重さなしグラフの最短経路](https://github.com/yuruhi/library/blob/master/Graph/ShortestPath.cpp)
- [木の最短経路](https://github.com/yuruhi/library/blob/master/Graph/ShortestPathTree.cpp)
- [重さなし木の最短経路](https://github.com/yuruhi/library/blob/master/Graph/ShortestPathUnweightedTree.cpp)
- [ダイクストラ法](https://github.com/yuruhi/library/blob/master/Graph/Dijkstra.cpp)
- [終点を決めてダイクストラ](https://github.com/yuruhi/library/blob/master/Graph/DijkstraST.cpp)
- [ダイクストラ法で最短パス](https://github.com/yuruhi/library/blob/master/Graph/DijkstraBuildPath.cpp)
- [ベルマンフォード法](https://github.com/yuruhi/library/blob/master/Graph/BellmanFord.cpp)
- [ワーシャルフロイド法](https://github.com/yuruhi/library/blob/master/Graph/WarashallFloyd.cpp)
- [辺を追加する](https://github.com/yuruhi/library/blob/master/Graph/WarashallFloydAddEdge.cpp)

### 木

- [木の直径](https://github.com/yuruhi/library/blob/master/Graph/Diametar.cpp)
- [木の直径のパス](https://github.com/yuruhi/library/blob/master/Graph/DiameterPath.cpp)
- [最小共通祖先(LCA)](https://github.com/yuruhi/library/blob/master/Graph/LCA.cpp)
- [木s-t間のパス](https://github.com/yuruhi/library/blob/master/Graph/BuildTreePath.cpp)
- [全方位木DP](https://github.com/yuruhi/library/blob/master/Graph/ReRooting.cpp)

### 最小全域木

- [クラスカル法](https://github.com/yuruhi/library/blob/master/Graph/Kruskal.cpp)

### 他

- [二部グラフ判定](https://github.com/yuruhi/library/blob/master/Graph/BipartiteGraph.cpp)
- [トポロジカルソート](https://github.com/yuruhi/library/blob/master/Graph/TopologicalSort.cpp)
- [強連結成分分解](https://github.com/yuruhi/library/blob/master/Graph/StronglyConnectedComponents.cpp)
- [全方位木DP](https://github.com/yuruhi/library/blob/master/Graph/ReRooting.cpp)

### フロー

- [フローテンプレート](https://github.com/yuruhi/library/blob/master/Graph/FlowTemplate.cpp)
- [二部マッチング](https://github.com/yuruhi/library/blob/master/Graph/BipartiteMatching.cpp)
- [二部マッチング（辺も求める）](https://github.com/yuruhi/library/blob/master/Graph/BipartiteMatching2.cpp)
- [Dinic法](https://github.com/yuruhi/library/blob/master/Graph/Dinic.cpp)
- [FordFulkerson法](https://github.com/yuruhi/library/blob/master/Graph/FordFulkerson.cpp)

### 構築・判定

- [全域木構築](https://github.com/yuruhi/library/blob/master/Graph/SpanningTree.cpp)
- [連結成分ごとに分ける](https://github.com/yuruhi/library/blob/master/Graph/ConnectedComponet.cpp)
- [連結判定](https://github.com/yuruhi/library/blob/master/Graph/isConnected.cpp)
- [閉路検出](https://github.com/yuruhi/library/blob/master/Graph/HasCycle.cpp)

## [Math](https://github.com/yuruhi/library/tree/master/Serch)

### 約数・倍数

- [約数列挙](https://github.com/yuruhi/library/blob/master/Math/Divisor.cpp)
- [拡張ユークリッドの互除法](https://github.com/yuruhi/library/blob/master/Math/extGcd.cpp)

### 素数

- [素数判定](https://github.com/yuruhi/library/blob/master/Math/isPrime.cpp)
- [エラトステネスの篩](https://github.com/yuruhi/library/blob/master/Math/Eratosthenes.cpp)
- [素数列挙](https://github.com/yuruhi/library/blob/master/Math/Primes.cpp)
- [素因数分解](https://github.com/yuruhi/library/blob/master/Math/PrimeFactor.cpp)
- [篩](https://github.com/yuruhi/library/blob/master/Math/Sieve.cpp)

### 組み合わせ

- [二項係数](https://github.com/yuruhi/library/blob/master/Math/Combi.cpp)
- [二項係数テーブル](https://github.com/yuruhi/library/blob/master/Math/Combination.cpp)

### mod

- [modint](https://github.com/yuruhi/library/blob/master/Math/modint.cpp)
- [実行時に法が決まるmodint](https://github.com/yuruhi/library/blob/master/Math/modintRuntime.cpp)
- [$g ^ x \equiv h \pmod{mod}$ なる $x$ を求める](https://github.com/yuruhi/library/blob/master/Math/BabystepGiantstep.cpp)

### 他

- [フィボナッチ数](https://github.com/yuruhi/library/blob/master/Math/Fibonacci.cpp)
- [転倒数](https://github.com/yuruhi/library/blob/master/Math/Inversion.cpp)
- [分割数](https://github.com/yuruhi/library/blob/master/Math/Partition.cpp)
- [N進法変換](https://github.com/yuruhi/library/blob/master/Math/Radix.cpp)

## [Serch](https://github.com/yuruhi/library/tree/master/Serch)

- [グリッド上のBFS](https://github.com/yuruhi/library/blob/master/Serch/GridBFS.cpp)

## [String](https://github.com/yuruhi/library/tree/master/String)

- [ローリングハッシュ](https://github.com/yuruhi/library/blob/master/String/RollingHash.cpp)
- [ZAlgorithm](https://github.com/yuruhi/library/blob/master/String/ZAlgorithm.cpp)

## [Utility](https://github.com/yuruhi/library/tree/master/Utility)

- [Run Length Encoding](https://github.com/yuruhi/library/blob/master/Utility/RLE.cpp)
- [累積和](https://github.com/yuruhi/library/blob/master/Utility/CulSum.cpp)
- [2次元累積和](https://github.com/yuruhi/library/blob/master/Utility/CulSum2D.cpp)
- [いもす法](https://github.com/yuruhi/library/blob/master/Utility/Imos.cpp)
- [2次元いもす法](https://github.com/yuruhi/library/blob/master/Utility/Imos2D.cpp)
- [一次関数を足すいもす法](https://github.com/yuruhi/library/blob/master/Utility/ImosLinear.cpp)
- [座標圧縮](https://github.com/yuruhi/library/blob/master/Utility/Compress.cpp)
- [Point](https://github.com/yuruhi/library/blob/master/Utility/Point.cpp)
- [Range](https://github.com/yuruhi/library/blob/master/Utility/Range.cpp)
- [乱数](https://github.com/yuruhi/library/blob/master/Utility/Random.cpp)
- [std::stringの操作](https://github.com/yuruhi/library/blob/master/Utility/ReaplaceAll.cpp)
- [std::vectorの操作](https://github.com/yuruhi/library/blob/master/Utility/VectorOperation.cpp)
- [RunLength圧縮みたいに保持する配列](https://github.com/yuruhi/library/blob/master/Utility/RunLengthArray.cpp)
  - （使用例）https://atcoder.jp/contests/agc029/submissions/12247826
-  [{ true, true, false ,true, true, true } -> { 1, 2, 0, 1, 2, 3}](https://github.com/yuruhi/library/blob/master/Utility/CountStraight.cpp) 
- [ { 1,2,3,2,1,2,1 } -> { [0-2], [2-4], [4-5], [5-6] } ](https://github.com/yuruhi/library/blob/master/Utility/splitRange.cpp)
- [文字列の対応する括弧の場所を探す](https://github.com/yuruhi/library/blob/master/Utility/BracketsPos.cpp)
- [うるう年判定](https://github.com/yuruhi/library/blob/master/Utility/isLeap.cpp)

## [template14](https://github.com/yuruhi/library/blob/master/template14.cpp)

C++14用テンプレート

## [template17](https://github.com/yuruhi/library/blob/master/template17.cpp)

C++17用テンプレート

## [dump](https://github.com/yuruhi/library/blob/master/dump.hpp)

デバッグ用出力関数

## Author

Atcoder id : yuruhiya

