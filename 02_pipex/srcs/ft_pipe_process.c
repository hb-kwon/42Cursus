/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:16:19 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/27 16:53:52 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** fd[0] -> read / fd[1] -> write
** 0 : STDIN, 1 : STDOUT
*/

/*
** if pipe() success,
** fd[0]는 파이프의 읽기 끝단을 의미하는 파일 디스크립터가 되고, 
** fd[1]은 파이프의 쓰기 끝단을 의미하는 파일 디스크립터가 된다.
*/

void	ft_pipe_in(t_info *info, char *argv[], char *envp[])
{
	info->f_in = open(argv[1], O_RDONLY);
	if (info->f_in < 0)
		ft_pipe_exit("Error : input file\n");
	close(info->fd[0]);
	if (dup2(info->fd[1], STDOUT_FILENO) == -1)
		ft_pipe_exit("Error : dup failed1\n");
	close(info->fd[1]);
	if (dup2(info->f_in, STDIN_FILENO) == -1)
		ft_pipe_exit("Error : dup failed2\n");
	close(info->f_in);
	ft_pipe_execute(info, argv[2], envp);
}

void	ft_pipe_out(t_info *info, char *argv[], char *envp[])
{
	info->f_out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (info->f_out < 0)
		ft_pipe_exit("Error : output file\n");
	close(info->fd[1]);
	if (dup2(info->fd[0], STDIN_FILENO) == -1)
		ft_pipe_exit("Error : dup failed3\n");
	close(info->fd[0]);
	if (dup2(info->f_out, STDOUT_FILENO) == -1)
		ft_pipe_exit("Error : dup failed4\n");
	close(info->f_out);
	ft_pipe_execute(info, argv[3], envp);
}

void	ft_pipe_process(t_info *info, char *argv[], char *envp[])
{
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(info->fd) == -1)
		ft_pipe_exit("Error: pipe failed\n");
	pid1 = fork();
	if (pid1 == -1)
		ft_pipe_exit("Error: fork failed\n");
	if (pid1 == 0)
		ft_pipe_in(info, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_pipe_exit("Error: fork failed\n");
	if (pid2 == 0)
		ft_pipe_out(info, argv, envp);
	close(info->fd[0]);
	close(info->fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
