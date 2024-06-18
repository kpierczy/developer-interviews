# ====================================================================================================================================
# @file       shell.bash
# @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
# @date       Tuesday, 18th June 2024 1:06:13 pm
# @modified   Tuesday, 18th June 2024 1:10:24 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
# @project    Developer Interviews
# @brief      Bash basics - shell manipulation
# 
# 
# @copyright Krzysztof Pierczyk © 2024
# ====================================================================================================================================

function foo() {

    local query="$1"

    case "$query" in
        on )
            set -o errexit;
            set -o nounset;
            set -o pipefail;
            ;;
        off )
            set +o errexit
            set +o nounset
            set +o pipefail
            ;;
    esac
}