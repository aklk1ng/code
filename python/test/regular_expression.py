import re

string = "sd[fsdfsd1413]4 @#$#df'lsdd,fd.fd/s"
# ^ 放在字符类的最开头表示取反
# 其他位置则没有特殊含义
print(re.findall("[^a-z]", string))
print(re.findall("[a-z^]", string))
print(re.findall("[a-z$]", string))
# \w 匹配任何字母和数字字符 => [a-zA-Z0-9_]
print(re.findall(r"\w", string))
# \W 匹配非任何字母和数字字符 => [^a-zA-Z0-9_]
print(re.findall(r"\W", string))
# \s 匹配任何空白字符 => [ \t\n\r\f\v]
print(re.findall(r"\s", string))
print(re.findall(r"[\s,.]", string))
# \S 匹配任何非空白字符 => [^ \t\n\r\f\v]
print(re.findall(r"\S", string))
# * 匹配前一个零次或多次(贪婪匹配,优先选择更多的子串)
print(re.findall(r"sd*", string))
# [sd]* 匹配[sd] 中零个或多个字母
print(re.findall(r"[sd]*", string))
# + 匹配一次或多次
print(re.findall(r"sd+", string))
# ? 匹配一次或零次
print(re.findall(r"sd?", string))
#         {m, n} m表示最少的匹配此时, n表示最多的匹配次数
# default: 0 ♾️
print(re.findall(r"sd{0,1}", string))


r = re.compile("[a-z]+")
# 从头开始匹配
m = r.match(string)
print(m.group())
print(m.start(), m.end())
print(m.span())
