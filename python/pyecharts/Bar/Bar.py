import pyecharts

bar1 = pyecharts.charts.Bar()
bar1.add_xaxis(["China", "America", "US"])
bar1.add_yaxis("GDP", [30, 20, 10], label_opts=pyecharts.options.LabelOpts(position="right"))
bar1.reversal_axis()
# bar1.render()

bar2 = pyecharts.charts.Bar()
bar2.add_xaxis(["China", "America", "US"])
bar2.add_yaxis("GDP", [50, 50, 50], label_opts=pyecharts.options.LabelOpts(position="right"))
bar2.reversal_axis()
# bar2.render()

timeline = pyecharts.charts.Timeline({"theme": pyecharts.globals.ThemeType.LIGHT})
timeline.add(bar1, "2021/GDP")
timeline.add(bar2, "2022/GDP")
timeline.add_schema(
  play_interval=1000,
  is_timeline_show=True,
  is_auto_play=True,
  is_loop_play=True
)
timeline.render("GDP_Show.html")
