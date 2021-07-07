./pipex infile ``ls -l'' ``wc -l'' outfile
./pipex ft_pipex.h ``awk '{printf"%s", $1}'''
./pipex ft_pipex.h ``'{printf"%s", $1}'''
./pipex ft_pipex.h ``cat -e''  ``awk -F, '{printf"%s", $0}''' dd
