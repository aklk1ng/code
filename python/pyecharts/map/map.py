import pyecharts
map = pyecharts.charts.Map()
data = [
    ("北京市", 99),
    ("上海市", 100),
    ("湖南省", 123),
    ("江西省", 66)
]

map.add("Map Show", data, "china")
map.set_global_opts(
    visualmap_opts=pyecharts.options.VisualMapOpts(
        is_show=True
    )
)
map.render()
