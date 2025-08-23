# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 10:00:00 by hmunoz-g          #+#    #+#              #
#    Updated: 2025/08/23 10:00:00 by hmunoz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ex15

CXX		= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

SRCDIR	= .
OBJDIR	= .obj
DEPDIR	= .dep

SOURCES	= main.cpp
OBJECTS	= $(SOURCES:%.cpp=$(OBJDIR)/%.o)
DEPENDS	= $(SOURCES:%.cpp=$(DEPDIR)/%.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR) $(DEPDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -MF $(DEPDIR)/$*.d -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(DEPDIR):
	mkdir -p $(DEPDIR)

complex_test:
	$(CXX) complex_test.cpp -o complex_test

clean:
	rm -rf $(OBJDIR) $(DEPDIR)

fclean: clean
	rm -f $(NAME)
	rm -f complex_test

re: fclean all

-include $(DEPENDS)
