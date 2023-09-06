import re
questions = re.split(r'([A-Z][^.?]*[.?])', input())
answers = ['Forty-two is' + question.strip()[7:]
           for question in questions if len(question.strip()) and question.strip()[:7] == "What is" and question.strip()[-1] == "?"]
for a in answers:
    print(a[:-1] + '.')
