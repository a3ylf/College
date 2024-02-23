:- dynamic livro/4.
% Livros disponíveis na biblioteca
livro(disponivel, 'Orgulho e Preconceito', romance, 'Jane Austen').
livro(disponivel, 'Os Miseráveis', romance, 'Victor Hugo').
livro(disponivel, 'Dom Casmurro', romance, 'Machado de Assis').
livro(disponivel, 'Anna Karenina', romance, 'Liev Tolstoi').
livro(disponivel, 'Os Catadores de Conchas', romance, 'Rosamunde Pilcher').
livro(disponivel, 'O Morro dos Ventos Uivantes', romance, 'Emily Bronte').
livro(disponivel, 'O Amor nos Tempos de Cólera', romance, 'Gabriel García
Márquez').
livro(disponivel, 'O Retrato de Dorian Gray', romance, 'Oscar Wilde').
livro(disponivel, 'Cem Anos de Solidão', romance, 'Gabriel García Márquez').
livro(disponivel, 'Crime e Castigo', romance, 'Fiódor Dostoiévski').
livro(disponivel, 'Frankenstein', ficcao, 'Mary Shelley').
livro(disponivel, 'Kindred laços de sangue', ficcao, 'Octavia Butler').
livro(disponivel, 'Farenheit 451', ficcao, 'Ray Bradbury').
livro(disponivel, 'Admirável mundo novo', ficcao, 'Aldous Huxley').
livro(disponivel, 'Um estranho numa Terra estranha', ficcao, 'Robert A.
Heilein').
livro(disponivel, 'Duna', ficcao, 'Frank Herbert').
livro(disponivel, '2001: Uma Odisséia no Espaço', ficcao, 'Arthur C. Clarke').
livro(disponivel, 'A Sutil Arte de Ligar o F*da-se', autoajuda, 'Mark Manson').
livro(disponivel, 'Por Que Fazemos o Que Fazemos?', autoajuda, 'Mário Sergio
Cortella').
livro(disponivel, 'O Poder do Agora', autoajuda, 'Eckhart Tolle').
livro(disponivel, 'O Poder do Hábito', autoajuda, 'Charles Duhigg').
livro(disponivel, 'As Cinco Linguagens do Amor', autoajuda, 'Gary Chapman').
livro(disponivel, 'As Sete Leis Espirituais do Sucesso', autoajuda, 'Deepak
Chopra').
livro(disponivel, 'Ansiedade: Como Enfrentar o Mal do Século', autoajuda,
'Augusto Cury').
% Livros emprestados da biblioteca
livro(emprestado, 'Os Miseráveis', romance, 'Victor Hugo').
livro(emprestado, 'O Amor nos Tempos de Cólera', romance, 'Gabriel García
Márquez').
livro(emprestado, 'Cem Anos de Solidão', romance, 'Gabriel García Márquez').
livro(emprestado, 'Andróides Sonham Com Ovelhas Elétricas? (Blade Runner)',
ficcao, 'Philip K. Dick').
livro(emprestado, 'Eu, robô', ficcao, 'Isaac Asimov').
livro(emprestado, 'Os despossuídos', ficcao, 'Ursula K. Le Guin').
livro(emprestado, 'Pai Rico, Pai Pobre', autoajuda, 'Robert Kiyosaki').
livro(emprestado, 'A Coragem de ser Imperfeito', autoajuda, 'Brené Brown').
livro(emprestado, 'O Poder da Ação', autoajuda, 'Paulo Vieira').
% Regra para emprestar um livro
emprestar(Livro, DataDevolucao) :-
retract(livro(disponivel, Livro, Genero, Autor)),
assertz(livro(emprestado, Livro, Genero, Autor)),
format('Livro ~w emprestado com sucesso! Data de devolução: ~w.~n', [Livro,
DataDevolucao]).
% Regra para devolver um livro
devolver(Livro) :-
retract(livro(emprestado, Livro, Genero, Autor)),
assertz(livro(disponivel, Livro, Genero, Autor)),
format('Livro ~w devolvido com sucesso!~n', [Livro]).
% Regra para consultar o status de um livro pelo nome
status(Livro) :-
livro(Estado, Livro, Genero, Autor),
format('Livro: ~w | Estado: ~w | Gênero: ~w | Autor: ~w~n', [Livro, Estado,
Genero, Autor]).
% Regra para listar os livros disponíveis de um gênero específico
liste_disp_genero(Genero) :-
livro(disponivel, Livro, Genero, Autor),
format('Livro disponível: ~w | Gênero: ~w | Autor: ~w~n', [Livro, Genero,
Autor]).
% Regra para listar os livros emprestados de um gênero específico
liste_emp_genero(Genero) :-
livro(emprestado, Livro, Genero, Autor),
format('Livro emprestado: ~w | Gênero: ~w | Autor: ~w~n', [Livro, Genero,
Autor]).
