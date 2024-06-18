# ====================================================================================================================================
# @file       scripting.ps1
# @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @date       Tuesday, 18th June 2024 1:06:13 pm
# @modified   Tuesday, 18th June 2024 1:15:36 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
# @project    Developer Interviews
# @brief      PoweShell basics - scripting
# 
# 
# @copyright Krzysztof Pierczyk © 2024
# ====================================================================================================================================

function Foo {
    $Invocation = (Get-Variable MyInvocation -Scope 1).Value
    $script_path = $Invocation.MyCommand.Path
    Split-Path $script_path
}