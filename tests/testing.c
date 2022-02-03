/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:02:52 by coder             #+#    #+#             */
/*   Updated: 2022/02/03 23:56:05 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "./unity/unity.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testando_is_invalid_arg_sem_parametro(void){
	TEST_ASSERT_EQUAL_INT (TRUE, is_invalid_arg(1, NULL));
}

void testando_com_um_arquivo_sem_ponto_cub(void){
	char **lek;
	lek = malloc(100);
	lek[0] = "./cube";
	lek[1] = "./test.cuba";
	TEST_ASSERT_EQUAL_INT (TRUE, is_invalid_arg(2, lek));
	free(lek);	
}

void testando_se_o_arquivo_existe(void)
{
	char **lek;
	lek = malloc(100);
	lek[0] = "./cube";
	lek[1] = "./test.cub";
	TEST_ASSERT_EQUAL_INT (TRUE, is_invalid_arg(2, lek));
	free(lek);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testando_is_invalid_arg_sem_parametro);
	RUN_TEST(testando_com_um_arquivo_sem_ponto_cub);
	RUN_TEST(testando_se_o_arquivo_existe);
    return UNITY_END();
}
