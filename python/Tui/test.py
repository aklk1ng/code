import pytermgui
import time

pytermgui.tim.print("[bold lightblue]Hello[/fg italic]!")

pytermgui.tim.print(
    "[bold]TIM[/] supports [italic]macros[/],"
    + " like [!upper]upper[/!] and [bold !gradient(56)]gradient[/!]."
)

pytermgui.tim.print(
    "We also support [skyblue underline ~https://ptg.bczsalba.com]"
    + "terminal hyperlinks[/]!"
)


def macro_time(fmt: str) -> str:
    return time.strftime(fmt)


pytermgui.tim.define("!time", macro_time)

with pytermgui.WindowManager() as manager:
    manager.layout.add_slot("Body")
    manager.add(
        pytermgui.Window("[bold]The current time is:[/]\n\n[!time 75]%c", box="EMPTY")
    )
