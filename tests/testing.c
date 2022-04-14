/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:02:52 by coder             #+#    #+#             */
/*   Updated: 2022/02/10 19:54:0 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <map.h>
#include "./unity/unity.h"

# define MAP_VALID "./assets/map_testes/valid_map.cub"
# define MAP_EMPTY "./assets/map_testes/empty_map.cub"
# define MAP_INVALID "./assets/map_testes/invalid_map.cub"
# define MAP_INVALID_TEXTURE "./assets/map_testes/invalid_texture_map.cub"
# define MAP_INVALID_CHARACTER "./assets/map_testes/invalid_character.cub"
# define MAP_INVALID_MAP_BORDER "./assets/map_testes/invalid_map_border.cub"
# define MAP_INVALID_SIZE_HEIGHT "./assets/map_testes/invalid_size_height_map.cub"
# define MAP_INVALID_WALL_INSIDE "./assets/map_testes/invalid_wall_inside.cub"
# define MAP_INVALID_MAP "./assets/map_testes/invalid_map.cub"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testando_is_invalid_arg_sem_parametro(void){
	TEST_ASSERT_EQUAL_INT (FALSE, is_invalid_arg(1, NULL));
}

void testando_com_um_arquivo_sem_ponto_cub(void){
	char *lek[2];
	lek[0] = "./cube";
	lek[1] = "./test.cuba";
	TEST_ASSERT_EQUAL_INT (FALSE, is_invalid_arg(2, lek));
}

void testando_se_o_arquivo_existe(void)
{
	char *lek[2];
	lek[0] = "./cube";
	lek[1] = "./test.cub";
	TEST_ASSERT_EQUAL_INT (FALSE, is_invalid_arg(2, lek));
}

void testando_se_o_arquivo_esta_vazio(void)
{
	TEST_ASSERT_NULL (store_content_map(MAP_EMPTY));
}

void testando_se_o_arquivo_nao_esta_vazio(void)
{
	TEST_ASSERT_NOT_NULL (store_content_map(MAP_VALID));
}

void testando_se_os_arquivos_da_textura_existe_e_sao_validos(void)
{
	char **map_content = remove_empty_line(store_content_map(MAP_VALID));
	char ***texture_path = valid_texture(map_content);
	TEST_ASSERT_EQUAL_INT (TRUE, texture_file_exist(texture_path));
	ft_free_split(map_content);
}

void testando_se_os_arquivos_da_textura_nao_existe(void)
{
	char **map_content = remove_empty_line(store_content_map(MAP_INVALID_TEXTURE));
	char ***texture_path = valid_texture(map_content);
	TEST_ASSERT_EQUAL_INT (FALSE, texture_file_exist(texture_path));
	ft_free_split(map_content);
}

void testando_se_as_texturas_sao_validas(void)
{
	char **map_content = store_content_map(MAP_VALID);
	TEST_ASSERT_NOT_NULL(valid_texture(map_content));
	ft_free_split(map_content);
}

void testando_se_as_texturas_nao_sao_validas(void)
{
	char **map_content = store_content_map(MAP_INVALID);
	TEST_ASSERT_NULL(valid_texture(map_content));
	ft_free_split(map_content);
}

void testando_se_existe_as_cores_do_chao_e_teto(void)
{
	char **map_content = remove_empty_line(store_content_map(MAP_VALID));
	TEST_ASSERT_NOT_NULL(valid_ceilling_and_floor_color(map_content));
}

void testando_se_nao_existe_as_cores_do_chao_e_teto(void)
{
	char **map_content = remove_empty_line(store_content_map(MAP_INVALID));
	TEST_ASSERT_NULL(valid_ceilling_and_floor_color(map_content));
}

void testando_se_a_blueprint_do_mapa_esta_sendo_retornada(void)
{
	char	**content_map;
	content_map = remove_empty_line(store_content_map(MAP_VALID));
	TEST_ASSERT_NOT_NULL(store_map_blueprint(content_map));
}

void testando_se_a_altura_do_mapa_e_invalido(void)
{
	char **content_map = store_map_blueprint(remove_empty_line(store_content_map(MAP_INVALID_SIZE_HEIGHT)));
	TEST_ASSERT_EQUAL_INT(FALSE, valid_size_map(content_map));
}

void testando_se_a_altura_e_largura_do_mapa_e_valido(void)
{
	char **content_map = store_map_blueprint(remove_empty_line(store_content_map(MAP_VALID)));
	TEST_ASSERT_EQUAL_INT(TRUE, valid_size_map(content_map));
}

void testando_se_o_mapa_tem_caracteres_invalidos(void)
{
	char **content = store_map_blueprint(remove_empty_line(store_content_map(MAP_INVALID_CHARACTER)));
	TEST_ASSERT_EQUAL_INT(FALSE, valid_characters(content));
}

void testando_se_o_mapa_tem_apenas_os_caracteres_permitidos(void)
{
	char **content = store_map_blueprint(remove_empty_line(store_content_map(MAP_VALID)));
	TEST_ASSERT_EQUAL_INT(TRUE, valid_characters(content));
}

// void testando_se_a_borda_do_map_esta_invalida(void)
// {
// 	char **content = store_map_blueprint(remove_empty_line(store_content_map(MAP_INVALID)));
// 	TEST_ASSERT_EQUAL_INT(FALSE, valid_edge(content));
// }

// void testando_se_a_borda_do_map_tem_apenas_1(void)
// {
// 	char **content = store_map_blueprint(remove_empty_line(store_content_map(MAP_VALID)));
// 	TEST_ASSERT_EQUAL_INT(TRUE, valid_edge(content));
// }

void testando_se_top_e_bottom_do_mapa_esta_certo(void)
{
	char **content = store_map_blueprint(remove_empty_line(store_content_map(MAP_VALID)));
	TEST_ASSERT_EQUAL_INT(TRUE, valid_top_bottom(content));
}

void testando_se_top_e_bottom_do_mapa_esta_errado(void)
{
	char **content = store_map_blueprint(remove_empty_line(store_content_map(MAP_INVALID_MAP_BORDER)));
	TEST_ASSERT_EQUAL_INT(FALSE, valid_top_bottom(content));
}

void testando_se_left_right_do_mapa_esta_certo(void)
{
	char **content = store_map_blueprint(remove_empty_line(store_content_map(MAP_VALID)));
	TEST_ASSERT_EQUAL_INT(TRUE, valid_left_right(content));
}

void testando_se_left_right_do_mapa_esta_errado(void)
{
	char **content = store_map_blueprint(remove_empty_line(store_content_map(MAP_INVALID_MAP_BORDER)));
	TEST_ASSERT_EQUAL_INT(FALSE, valid_left_right(content));
}

void testando_se_as_paredes_dentro_do_mapa_sao_validas(void)
{
	char **map = remove_empty_line(store_content_map(MAP_VALID));
	char **content = store_map_blueprint(map);
	TEST_ASSERT_EQUAL_INT(TRUE, valid_wall_inside_map(content));
}

void testando_se_tem_alguma_parede_invalida_dentro_do_mapa(void)
{
	char **content = store_map_blueprint(remove_empty_line(store_content_map(MAP_INVALID_WALL_INSIDE)));
	TEST_ASSERT_EQUAL_INT(FALSE, valid_wall_inside_map(content));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testando_is_invalid_arg_sem_parametro);
	RUN_TEST(testando_com_um_arquivo_sem_ponto_cub);
	RUN_TEST(testando_se_o_arquivo_existe);
	RUN_TEST(testando_se_o_arquivo_esta_vazio);
	RUN_TEST(testando_se_o_arquivo_nao_esta_vazio);
	RUN_TEST(testando_se_as_texturas_nao_sao_validas);
	RUN_TEST(testando_se_as_texturas_sao_validas);
	RUN_TEST(testando_se_os_arquivos_da_textura_existe_e_sao_validos);
	RUN_TEST(testando_se_os_arquivos_da_textura_nao_existe);
	RUN_TEST(testando_se_existe_as_cores_do_chao_e_teto);
	RUN_TEST(testando_se_nao_existe_as_cores_do_chao_e_teto);
	RUN_TEST(testando_se_a_blueprint_do_mapa_esta_sendo_retornada);
	RUN_TEST(testando_se_a_altura_do_mapa_e_invalido);
	RUN_TEST(testando_se_a_altura_e_largura_do_mapa_e_valido);
	// RUN_TEST(testando_se_a_borda_do_map_tem_apenas_1);
	// RUN_TEST(testando_se_a_borda_do_map_esta_invalida);
	RUN_TEST(testando_se_o_mapa_tem_apenas_os_caracteres_permitidos);
	RUN_TEST(testando_se_o_mapa_tem_caracteres_invalidos);
	RUN_TEST(testando_se_top_e_bottom_do_mapa_esta_certo);
	RUN_TEST(testando_se_top_e_bottom_do_mapa_esta_errado);
	RUN_TEST(testando_se_left_right_do_mapa_esta_certo);
	RUN_TEST(testando_se_left_right_do_mapa_esta_errado);
	RUN_TEST(testando_se_as_paredes_dentro_do_mapa_sao_validas);
	RUN_TEST(testando_se_tem_alguma_parede_invalida_dentro_do_mapa);
    return UNITY_END();
}
