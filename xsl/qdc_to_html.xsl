<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:variable name="BASEURL" select="$baseUrl"/>
    <xsl:variable name="PATH" select="$path"/>
    <xsl:template match="/">      
        <div><table cellspacing="3" cellpadding="3"><tbody>
            <tr><td>
            <xsl:for-each select="/*/*">
                <xsl:variable name="FULLFIELD" select="name()"/>
                <xsl:variable name="FIELD" select="substring-after(name(),':')"/>
                <xsl:variable name="DATA" select="text()"/>               
                <xsl:if test="$DATA != ' '">
                    <xsl:if test="$FIELD = 'creator'">
                        <h3><xsl:value-of select="text()"/></h3>
                    </xsl:if>
                    <xsl:if test="$FIELD = 'title'">
                        <h2><xsl:value-of select="text()"/></h2>
                    </xsl:if>
                    <xsl:if test="$FIELD = 'date'">
                        <h3><xsl:value-of select="text()"/></h3>
                    </xsl:if>
                </xsl:if>
                
            </xsl:for-each>       
            </td></tr></tbody></table></div>
        
    </xsl:template>    
</xsl:stylesheet>
