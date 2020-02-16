import random
class my21(object):
	def __init__(self):


	def run():
		monte = random.suffle(baralho(),random)
		qtd,score,score2 = 1,0,0
		
		carta1 = monte.pop()
		carta2 = monte.pop()
		
		if carta1[0] == carta2[0]: #posso ter duas maos
			qtd = 2
		
		for i in range(qtd):
			score = carta1[0] if i == 0 else carta2[0]
			if (carta1[0] if i == 0 else carta2[0]) == 1:
				score2 = score + 10
			elif:
				score
			
			
			while True:
				op = input('deseja mais uma carta?s/n')
				while op != 'n' and op != 's'
					op = input('Opcao invalida!,deseja mais uma carta?s/n')
				
				if op == 's':
					
		
	
		
	def baralho(): # case if 1, i can or not add 10 in score 
		b = []
		for i in range(10):
			b.append((i,'Paus'))
			b.append((i,'Ouros'))
			b.append((i,'Copas'))
			b.append((i,'Espadas'))
		b += [(10,'Valete')for i in range(4)]
		b += [(10,'Dama')for i in range(4)]
		b += [(10,'Rei')for i in range(4)]
		return b
