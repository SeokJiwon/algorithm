'''
문자열의 일부 자릴수가 영단어인 경우 원래 숫자로 바꿔서 return
ex)
"one4seveneight"	1478
'''

def solution(s):

    answer = ""
    
    dict={"zero":"0", "one":"1", "two":"2", "three":"3", "four":"4", "five":"5", "six":"6", "seven":"7", "eight":"8", "nine":"9"}
    tmp = list(dict.keys())

    for key in tmp:
        if key in s:
            s = s.replace(key, dict[key])
            
    answer = int(s)
    return answer