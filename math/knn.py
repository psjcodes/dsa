import heapq
from collections import Counter
from typing import List, Tuple, Any
import numpy as np
from numpy.typing import NDArray

class MyKMinHeap:

    def __init__(self, k: int) -> None:
        self._heap: List[Tuple[float, Any]] = []
        self._k = k

    def push(self, item: Any, priority: np.float64) -> None:
        node = (-priority, item)
        if len(self._heap) < self._k:
            heapq.heappush(self._heap, node)
        elif -priority > self._heap[0][0]:
            heapq.heapreplace(self._heap, node)

    def pop(self) -> Any:
        _, item = heapq.heappop(self._heap)
        return item
    
    def get_items(self) -> List[Any]:
        return [item for _, item in self._heap]


class MyKNN:

    def __init__(
        self,
        data: NDArray[np.float64],
        labels: NDArray[Any],
        k: int = 1,
        method: str = "linear",
    ) -> None:
        self._data = data
        self._labels = labels
        self._k = k
        self._method = method

    def _euclidean_distance(self, x: NDArray[np.float64], y: NDArray[np.float64]) -> np.float64:
        return np.dot(x - y, x - y)

    def _linear_search(self, input: NDArray[np.float64], top_k: MyKMinHeap) -> None:
        for i, x in enumerate(self._data):
            dist = self._euclidean_distance(x, input)
            top_k.push(item=i, priority=dist)

    def knn_search(self, input: NDArray[np.float64]) -> dict[Any, int]:
        top_k = MyKMinHeap(k=self._k)
        if self._method == "linear":
            self._linear_search(input=input, top_k=top_k)

        knn_labels = [self._labels[i] for i in top_k.get_items()]
        count_labels = Counter(knn_labels)
        return {label: count for label, count in count_labels.items()}
    
    def classify(self, input: NDArray[np.float64]) -> Any:
        knn = self.knn_search(input=input)
        return max(knn, key=knn.get)




            
