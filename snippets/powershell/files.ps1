# ====================================================================================================================================
# @file       files.ps1
# @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @date       Tuesday, 18th June 2024 1:06:13 pm
# @modified   Tuesday, 18th June 2024 1:15:24 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
# @project    Developer Interviews
# @brief      PoweShell basics - files manipulation
# 
# 
# @copyright Krzysztof Pierczyk © 2024
# ====================================================================================================================================

function Foo {

    param(
        [string]$file_path,
        [string]$line_pattern,
        [string]$new_line,
        [string]$output_file = $file_path
    )
    
    $file_content = Get-Content $file_path
    $file_content | ForEach-Object {
        if($_ -match "$line_pattern") {
            $new_line
        } else {
            $_
        }
    } | Set-Content $output_file
}