# ====================================================================================================================================
# @file       utils.ps1
# @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @date       Tuesday, 18th June 2024 1:06:13 pm
# @modified   Tuesday, 18th June 2024 1:15:58 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
# @project    Developer Interviews
# @brief      Python - simple utilities
# 
# 
# @copyright Krzysztof Pierczyk © 2024
# ====================================================================================================================================

import platform
import pathlib
import tempfile

def foo(
    content : list
) -> pathlib.Path:

    extensions = {
        'Windows': '.ps1',
        'Linux'  : '.bash',
    }

    if not platform.system() in extensions:
        raise NotImplementedError(f'Platform {platform.system()} is not supported')
    else:
        extension = extensions[platform.system()]

    with tempfile.NamedTemporaryFile(mode='w', suffix=extension, delete=False) as f:
        f.write('\n'.join(content))
        return pathlib.Path(f.name)