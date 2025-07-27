library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity testadder is
end;

architecture bench of testadder is
  component adder1
	port (a,b 	: in STD_LOGIC_VECTOR (3 downto 0);
		 sum : out STD_LOGIC_VECTOR(3 downto 0));
  end component;

  signal a,b : STD_LOGIC_VECTOR (3 downto 0);
  signal sum : STD_LOGIC_VECTOR (3 downto 0);

begin   
 a   <= "0000" , "0010" after 5 ns  , "0011" after 10ns; 
 b   <= "0000" , "0010" after 5 ns  , "0001" after 10ns; 
 
 m: adder1 port map (a,b,sum);

end bench;