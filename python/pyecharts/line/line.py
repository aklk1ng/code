import pyecharts

line = pyecharts.charts.Line()
line.add_xaxis(["1", "2", "3"])
line.add_yaxis("GDP", [30, 20, 10])
line.set_global_opts(
  title_opts=pyecharts.options.TitleOpts(title="GDP Show",
                                         pos_left="center",
                                         pos_bottom="1%"),
  legend_opts=pyecharts.options.LegendOpts(is_show=True),
  toolbox_opts=pyecharts.options.ToolboxOpts(is_show=True),
  visualmap_opts=pyecharts.options.VisualMapOpts(is_show=True)
)
line.render()
