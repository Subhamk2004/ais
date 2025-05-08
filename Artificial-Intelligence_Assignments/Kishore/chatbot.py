print("🎓 Welcome to College Buddy Chatbot!")
print("We are the best chatbot in the entire universe for college-related queries.")
print("Ask me about colleges, branches, or cut-offs.")

while True:
    user_input  = input("You: ").lower()
    
    if user_input == "what is your name?":
        print("Bot: My name is Assistant! Happy to help you out with your college enquiries!")
    elif user_input == "What are the best engineering branches?":
        print("Bot: Computer Engineering, IT Engineering, ENTC Engineering")
    elif user_input == "what are the best colleges from pune?":
        print("Bot: COEP,PICT,VIT,CUMMINS,PCCOE")
    elif user_input == "what are the top branches cut-off for coep?":
        print("IT DEPT = 99.4%\nEntc = 99.2%\nComputer = 99.8%")
    elif user_input == "bye":
        print("Bot: Thankyou for chatting with us. Enjoy your day!")
        break
    else :
        print("Bot: Sorry, I don't have an answer for that")


#  Simple re baba, kuch nai krna bhot easy h chill mar simple type krley bss

# import re

# print("🎓 Welcome to College Buddy Chatbot!")
# print("Ask me about colleges, branches, or cut-offs.")
# print("Type 'bye' to exit.\n")

# while True:
#     user_input = input("You: ").lower()

#     if user_input in ["what is your name?", "hello"]:
#         print("Bot: My name is College Buddy! Happy to help you out with your college enquiries!")

#     elif re.search(r"what are.*pune", user_input):
#         print("Bot: COEP, PICT, VIT, CUMMINS, PCCOE")

#     elif user_input == "which are the best engineering branches?":
#         print("Bot: Computer Engineering, IT Engineering, ENTC Engineering")

#     elif user_input == "what are the top branch cut-offs for coep?":
#         print("Bot: Computer Engineering: 99.8 percentile\nDoes not have IT branch\nENTC Engineering: 99.2 percentile")

#     elif user_input == "what are the top branch cut-offs for pict?":
#         print("Bot: Computer Engineering: 99.4 percentile\nIT Engineering: 98.6 percentile\nENTC Engineering: 97.2 percentile")

#     elif user_input == "what are the top branch cut-offs for vit?":
#         print("Bot: Computer Engineering: 99.8 percentile\nIT Engineering: 97.1 percentile\nENTC Engineering: 96.2 percentile")

#     elif user_input == "what are the top branch cut-offs for cummins?":
#         print("Bot: Computer Engineering: 99.8 percentile\nDoes not have IT branch\nENTC Engineering: 99.2 percentile")

#     elif user_input == "what are the top branch cut-offs for pccoe?":
#         print("Bot: Computer Engineering: 99.8 percentile\nDoes not have IT branch\nENTC Engineering: 99.2 percentile")

#     elif user_input == "when do college admissions start?":
#         print("Bot: Admissions generally start around August.")

#     elif user_input == "bye":
#         print("Bot: Thank you for using College Buddy. Goodbye!")
#         break

#     else:
#         print("Bot: Sorry, I don't have an answer for that.")
