parties_names = []
votes_lines = []
with open("parties.txt") as f:
     parties_names = f.read().splitlines()
with open("votes.txt") as f:
     votes_lines.extend([line for line in f.read().splitlines() if len(line.split()) == 4])
d = {}
total_votes = 0
for line in votes_lines:
     total_votes+=6
     
for party in parties_names:
     party_votes = 0
     for line in votes_lines:
          for i,name in enumerate(line[1::].split()):
               if name == party:
                    party_votes+=(3-i)
     d[party] = round(100*(party_votes/total_votes))
     print(d[party])
with open("result.txt",'w') as f:
     for party,num in d.items():
          f.write(party+" "+str(num)+"%") 
                    

          
     
          

