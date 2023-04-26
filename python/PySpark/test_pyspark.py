import os

import pyspark

os.environ["PYSPARK_PYTHON"] = "/usr/bin/python3"
conf = pyspark.SparkConf()
conf.setMaster("local[*]")
conf.setAppName("test_pyspark")
sc = pyspark.SparkContext(conf=conf)


def add(data):
    return 10 * data


# rdd = sc.parallelize("abcd")
rdd2 = sc.parallelize([1, 2, 3, 4, 5, 5])
rdd3 = sc.parallelize([("a", 1), ("a", 3), ("b", 1), ("b", 1)])
# rdd3 = sc.parallelize({"xxx": "fsdfasd", "ooo": "fasdf"})
# print(sc.version)
# print(rdd.collect())
# print(rdd2.collect())
# print(rdd3.collect())

# rdd = sc.textFile("/home/cjh/tmux-client-182292.log")
# print(rdd2.map(add).collect())
print(rdd2.map(lambda x: x * 10).collect())
print(rdd3.reduceByKey(lambda a, b: a + b).collect())
print(rdd2.filter(lambda x: x % 2 == 0).collect())
print(rdd2.distinct().collect())
print(rdd3.sortBy(lambda x: x[1], ascending=False, numPartitions=1).collect())
sc.stop()
