#!/usr/bin/env python3
#auxgrep

import subprocess
import time
out = 'evilCORP.dll'


def compiled():

	time.sleep(2)
	subprocess.run(f'x86_64-w64-mingw32-gcc DLL_4W-injection.c -o {out} \
	-shared',shell=True)
	print(f"Successful and saved as {out}")

compiled();
