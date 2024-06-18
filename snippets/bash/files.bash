# ====================================================================================================================================
# @file       files.bash
# @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @date       Tuesday, 18th June 2024 1:06:13 pm
# @modified   Tuesday, 18th June 2024 1:10:19 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
# @project    Developer Interviews
# @brief      Bash basics - files manipulation
# 
# 
# @copyright Krzysztof Pierczyk © 2024
# ====================================================================================================================================

function foo() {

    local file_="$1"

    [[ -f "$file_" ]] || return 1

    wc -l "$file_" | awk '{ print $1 }'
}

# ================================================================================================================================== #

function bar() {

    local file_="$1"
    local line_="$2"

    [[ -f "$file_" ]] || return 1

    local lines_num=$(get_file_lines_num "$file_")
    (( $lines_num >= $line_ )) || return 1

    sed "${line_}q;d" "$file_"
}

# ================================================================================================================================== #
